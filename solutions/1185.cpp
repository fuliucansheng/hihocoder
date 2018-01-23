#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
using namespace std;
const int maxn = 20010;
vector<int> graph[maxn];
set<int> scc_graph[maxn];
int pre[maxn], low[maxn], scc[maxn], scc_vis[maxn], scc_rec[maxn], arr[maxn], dfs_clock = 0, scc_cnt = 0, n, m;
stack<int> S;
void dfs(int u){
    pre[u] = low[u] = ++dfs_clock;
    S.push(u);
    for(auto v:graph[u])
        if(!pre[v]) dfs(v), low[u] = min(low[u], low[v]);
        else if(!scc[v]) low[u] = min(low[u], pre[v]);
    if(low[u] == pre[u]){
        scc_cnt++;
        for(;;){
            int x = S.top(); S.pop();
            scc[x] = scc_cnt, scc_rec[scc_cnt] += arr[x];
            if(x == u) break;
        }
    }
}
void dfs_(int u){
    int r = 0;
    for(auto v:scc_graph[u]) {
        if(!scc_vis[v]) dfs_(v);
        r = max(r, scc_vis[v]);
    }
    scc_vis[u] = r + scc_rec[u];
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(pre, 0, sizeof(pre));memset(scc_rec, 0, sizeof(scc_rec));memset(scc_vis, 0, sizeof(scc_vis));
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    dfs(1);
    for(int i=1;i<=n;i++) for(auto v:graph[i]) if(scc[v] != scc[i]) scc_graph[scc[i]].insert(scc[v]);
    dfs_(scc[1]);
    cout<<scc_vis[scc[1]]<<endl;
    return 0;
}
