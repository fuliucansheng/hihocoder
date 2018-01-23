#include <iostream>
#include <map>
#include <set>
using namespace std;
#define g(n) graph[n.first][n.second]
#define nl(n) n.first > 0 ? node(n.first-1, n.second) : node(-1, -1)
#define nlt(n) n.first > 0 && n.second > 0 ? node(n.first-1, n.second-1) : node(-1, -1)
#define nlb(n) n.first > 0 && n.second < mm-1 ? node(n.first-1, n.second+1) : node(-1, -1)
#define nr(n) n.first < nn-1 ? node(n.first+1, n.second) : node(-1, -1)
#define nrt(n) n.first < nn-1 && n.second > 0 ? node(n.first+1, n.second-1) : node(-1, -1)
#define nrb(n) n.first < nn-1 && n.second < mm-1 ? node(n.first+1, n.second+1) : node(-1, -1)
#define nt(n) n.second > 0 ? node(n.first, n.second-1) : node(-1, -1)
#define nb(n) n.second < mm-1 ? node(n.first, n.second+1) : node(-1, -1)
#define st(n) {nl(n), nlt(n), nlb(n), nr(n), nrt(n), nrb(n), nt(n), nb(n)}
typedef pair<int,int> node, value;
const int maxn = 12;
int graph[maxn][maxn], mm, nn;
map<node,value> dict;
void update(node d, int type){
    set<node> ss = st(d);
    if(type == 0) { for(auto s:ss) if(s!=node(-1,-1) && dict[s].second) dict[s].second--; }
    else for(auto s:ss) if(s!=node(-1,-1) && dict[s].first && dict[s].second) dict[s].first--,dict[s].second--;
}
void solve(int &mine, int &no_mine){
    set<node> unknow;
    for(int i=0;i<nn;i++)
        for(int j=0;j<mm;j++)
            if(g(node(i,j)) != -1){
                set<node> ss = st(node(i,j));
                dict[node(i,j)].first = g(node(i,j));
                dict[node(i,j)].second = 0;
                for(auto s:ss) if(s != node(-1,-1) && g(s) == -1) dict[node(i,j)].second++;
            }else unknow.insert(node(i,j));
    while(true){
        int rec = mine + no_mine;
        for(auto d:dict){
            if(g(d.first) != -1 &&d.second.first == 0){
                set<node> ss = st(d.first);
                for(auto s:ss) if(unknow.find(s) != unknow.end()) update(s, 0), no_mine++, unknow.erase(s);
            } else if(g(d.first) != -1 && d.second.first == d.second.second){
                set<node> ss = st(d.first);
                for(auto s:ss) if(unknow.find(s) != unknow.end()) update(s, 1), mine++, unknow.erase(s);
            }
        }
        if(rec == (mine + no_mine)) break;
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        cin>>nn>>mm;
        dict.clear();
        for(int i=0;i<nn;i++) for(int j=0;j<mm;j++) cin>>graph[i][j];
        int mine = 0, no_mine = 0;
        solve(mine, no_mine);
        cout<<mine<<" "<<no_mine<<endl;
    }
    return 0;
}
