#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int maxn = 20010;
vector<int> graph[maxn];
set<int> rec[maxn];
int pre[maxn], low[maxn], group[maxn], dfs_clock = 0, n, m;
int dfs(int u, int fa){
    int lowu = pre[u] = ++dfs_clock;
    for(auto v:graph[u]){
        if(!pre[v]){
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if(lowv > pre[u]) rec[u].insert(v), rec[v].insert(u);
        }else if(pre[v] < pre[u] && v != fa) lowu = min(lowu, pre[v]);
    }
    low[u] = lowu;
    return lowu;
}
void dfs_(int u, int g){
    group[u] = g;
    for(auto v:graph[u]) if(rec[u].find(v) == rec[u].end() && !group[v]) dfs_(v, g);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    dfs(1, -1);
    memset(group, 0, sizeof(group));
    int gc = 0;
    for(int i=1;i<=n;i++) if(!group[i]) dfs_(i,i), gc++;
    cout<<gc<<endl;
    for(int i=1;i<=n;i++) cout<<group[i]<<" ";
    cout<<endl;
    return 0;
}
