#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1010;
int rec[maxn], graph[maxn][maxn], vis[maxn], m, n;
bool dfs(int u){
    for(int i=1;i<=n;i++) if(graph[u][i] && !vis[i] && (vis[i] = 1) && (!rec[i] || dfs(rec[i]))) return rec[i] = u, true;
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(graph, 0, sizeof(graph));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v; cin>>u>>v;
        graph[u][v] = graph[v][u] = 1;
    }
    int rs = 0;
    for(int i=1;i<=n;i++){
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) rs++;
    }
    cout<<rs/2<<endl;
    return 0;
}
