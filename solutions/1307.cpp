#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> maxmin;
int rec[1000];
struct tower{
    int x,y,r;
    tower(){}
    tower(int xx,int yy,int rr):x(xx),y(yy),r(rr){}
    bool cross(tower b){
        long long dx = x - b.x,dy = y - b.y,dr = r + b.r;
        long long dt = dx*dx + dy*dy;
        return dt <= dr*dr;
    }
};
int find(int node){
    while(rec[node] != node) node = rec[node];
    return node;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t,w,h,n;
    tower tow;
    vector<tower> dict;
    map<int,maxmin> record;
    cin>>t;
    while(t--){
        cin>>w>>h>>n;
        for(int i=0;i<1000;i++) rec[i] = i;
        dict.clear(),record.clear();
        for(int i=0;i<n;i++){
            cin>>tow.x>>tow.y>>tow.r,dict.push_back(tow);
            for(int j=i-1;j>=0;j--)
                if(dict[j].cross(tow)){
                    int rj = find(j),ri = find(i);
                    if(rj < ri) rec[ri] = rj;
                    else if(rj > ri) rec[rj] = ri;
                }
        }
        bool status = true;
        for(int i=0;i<n;i++){
            int root = find(i);
            if(record.find(root) == record.end()) record[root] = maxmin(dict[i].y+dict[i].r,dict[i].y-dict[i].r);
            record[root].first = max(record[root].first,dict[i].y + dict[i].r);
            record[root].second = min(record[root].second,dict[i].y - dict[i].r);
            if(record[root].first >= h && record[root].second <= 0){
                status = false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(status) cout<<"YES"<<endl;
    }
    return 0;
}
