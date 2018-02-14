#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define maxn 1000010
const int prec = 6;
const double pi = acos(-1.0);

int N,M;

int geohash[10];

vector<pair<double, double> > vec[maxn];

void encode(double x, double y, int precision)
{
    double latIn[] = {-90, 90};
    double lonIn[] = {-180, 180};
    int len = precision * 5;
    int gt = 0;
    int bits = 0;
    int i;
    double mid;
    for(i=0;i<len;i++)
    {
        if((i%2)==0)
        {
            mid=(lonIn[0]+lonIn[1])/2.0;
            if(y>mid)
            {
                bits=bits*2+1;
                lonIn[0]=mid;
            }
            else
            {
                bits=bits*2;
                lonIn[1]=mid;
            }
        }
        else
        {
            mid=(latIn[0]+latIn[1])/2.0;
            if(x>mid)
            {
                bits=bits*2+1;
                latIn[0]=mid;
            }
            else
            {
                bits=bits*2;
                latIn[1]=mid;
            }
        }
        if((i%5)==4)
        {
            geohash[gt++]=bits;
            bits=0;
        }
    }
}

struct node
{
    int next[32];
}nodes[maxn];

int root=0, pt=0;

double dir[9][2]={{0,0},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
double dx, dy;

void init()
{
    memset(nodes[root].next, -1, sizeof(nodes[root].next));
    vec[root].clear();
    dx = 180.0 / (1 << 15);
    dy = 360.0 / (1 << 15);
}


void insert(int geohash[], double x, double y)
{
    int i;
    int curr=root;
    for(i=0;i<prec;i++)
    {
        if(nodes[curr].next[geohash[i]]==-1)
        {
            pt++;
            memset(nodes[pt].next, -1, sizeof(nodes[pt].next));
            vec[pt].clear();
            nodes[curr].next[geohash[i]]=pt;
        }
        curr=nodes[curr].next[geohash[i]];
    }
    vec[curr].push_back(make_pair(x,y));
    
}

int ans;

int query(int geohash[])
{
    int i, curr=root;
    for(i=0;i<prec;i++)
    {
        if(nodes[curr].next[geohash[i]]==-1)
            return -1;
        curr=nodes[curr].next[geohash[i]];
    }
    return curr;
}

double dis(double x1, double y1, double x2, double y2)
{
    double r = 6000000;
    x1 = x1 * pi / 180;
    y1 = y1 * pi / 180;
    x2 = x2 * pi / 180;
    y2 = y2 * pi / 180;
    double l = r * acos( cos(x1-x2 ) * cos(y1 - y2) );
    return l;
}

void gao(double x, double y, int prec)
{
    double tmpx, tmpy;
    int i,id,tmpi;
    set<int> s;
    s.clear();
    for(i=0;i<9;i++)
    {
        tmpx=x+dir[i][0]*dx;
        tmpy=y+dir[i][1]*dy;
        encode(tmpx,tmpy,prec);
        id=query(geohash);
        if(id==-1)
            continue;
        if(s.count(id)>0)
            continue;
        s.insert(id);
        for(tmpi=0;tmpi<vec[id].size();tmpi++)
        {
            if(dis(vec[id][tmpi].first, vec[id][tmpi].second, x, y)<500.0)
                ans++;
        }
    }
}

int main()
{
    scanf("%d%d",&N,&M);
    double x,y;
    int i;
    init();
    for(i=0;i<N;i++)
    {
        scanf("%lf %lf",&x,&y);
        encode(x,y,prec);
        insert(geohash,x,y);
    }
    for(i=0;i<M;i++)
    {
        scanf("%lf %lf",&x,&y);
        ans=0; 
        gao(x,y,prec);
        printf("%d\n",ans);
    }
    return 0;
}

