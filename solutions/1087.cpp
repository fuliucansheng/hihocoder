#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
bool vis[maxn];
set<int> graph[maxn];
int dp[maxn][1<<maxn], n, m;
int dfs(int u, int c){
    if(dp[u][c] != -1) return dp[u][c];
    int ret = 0;
    vis[u] = true;
    for(auto v:graph[u]) {
        if(v == 1 && c == (1 << n) - 1) ret++;
        else if(!vis[v]) ret += dfs(v, c | (1 << (v - 1)));
    }
    vis[u] = false;
    dp[u][c] = ret;
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp)); memset(vis, 0, sizeof(vis));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v; cin>>u>>v;
        graph[u].insert(v);
    }
    int ans = dfs(1, 1);
    cout<<ans<<endl;
    return 0;
}