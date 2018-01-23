#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1050;
int vis[maxn], graph[maxn][maxn], rec[maxn], m, n;
bool dfs(int u){
    for(int i=1;i<=n;i++) if(graph[u][i] && !vis[i] && (vis[i] = 1) && (!rec[i] || dfs(rec[i]))) return rec[i] = u, true;
    return false;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(graph, 0, sizeof(graph));
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int u,v; cin>>u>>v;
        graph[u][v] = graph[v][u] = 1;
    }
    int r = 0;
    for(int i=1;i<=n;i++){
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) r++;
    }
    cout<<r/2<<endl<<n-r/2<<endl;
    return 0;
}
