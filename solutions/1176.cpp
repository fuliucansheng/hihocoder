#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int m, n, deg[maxn], vis[maxn];
vector<int> graph[maxn];
void dfs(int u){
    vis[u] = 1;
    for(auto v : graph[u]) if(!vis[v]) dfs(v);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(deg, 0, sizeof(deg)); memset(vis, 0, sizeof(vis));
    int u, v; cin>>n>>m;
    for(int i = 0; i < m; i++) {
        cin>>u>>v;
        deg[u]++, deg[v]++, graph[u].push_back(v), graph[v].push_back(u);
    }
    int c = 0;
    for(int i = 1; i <= n; i++) if(deg[i]%2 == 1) c++;
    if(c != 0 && c != 2) return cout<<"Part"<<endl, 0;
    dfs(1);
    bool s = true;
    for(int i = 1; i <= n; i++) if(!vis[i]) s = false;
    if(s) cout<<"Full"<<endl; else cout<<"Part"<<endl;
    return 0;
}
