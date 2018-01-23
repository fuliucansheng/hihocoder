#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10, maxm = 1e6+10;
struct node{
    int s,t,c;
    node(){}
};
int group[maxn];
bool cmp(node a, node b){ return a.c < b.c; }
int find_group(int x){ return x == group[x] ? x : find_group(group[x]); }
void union_group(int x, int y){
    int dx = find_group(x), dy = find_group(y);
    group[dx] = group[dy] = min(dx, dy);
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n,m,cost = 0;
    cin>>n>>m;
    node store[m];
    for(int i=0;i<m;i++) cin>>store[i].s>>store[i].t>>store[i].c;
    sort(store, store+m, cmp);
    for(int i=1;i<=n;i++) group[i] = i;
    for(int i=0;i<m;i++){
        int ds = find_group(store[i].s), dt = find_group(store[i].t);
        if(ds != dt) cost += store[i].c, union_group(ds, dt);
    }
    cout<<cost<<endl;
    return 0;
}
