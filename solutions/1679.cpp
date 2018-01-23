#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> graph[maxn];
int fa[maxn], vis[maxn];
queue<int> Q;
void dfs(int u){
    if(graph[u].size() == 0) Q.push(u);
    else if(graph[u].size() == 1) dfs(graph[u][0]);
    else dfs(min(graph[u][0], graph[u][1])), dfs(max(graph[u][0], graph[u][1]));
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(fa, 0, sizeof(fa)); memset(vis, 0, sizeof(vis));
    int n, r = 0; cin>>n;
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), fa[v] = u;
    }
    for(int i=1;i<=n;i++) if(fa[i] == 0) r = i;
    dfs(r);
    while(!Q.empty()){
        int f = Q.front(); Q.pop();
        while(f) {
            if(!vis[f]) vis[f] = 1, cout<<f<<endl;
            else break;
            f = fa[f];
        }
    }
    return 0;
}
