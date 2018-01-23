#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 8050<<1;
int vis[maxn], stk[maxn];
vector<int> graph[maxn];
bool dfs(int u,int t){
    stk[++stk[0]] = u;vis[u] = 1;
    if(u == t) return true;
    for(auto v:graph[u]) if(!vis[v] && dfs(v,t)) return true;
    return false;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(vis, 0, sizeof(vis));memset(stk, 0, sizeof(stk));
    int m,n,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>u>>v;u++;v++;
        graph[u].push_back(v^1), graph[v].push_back(u^1);
    }
    for(int i=2;i<=2*n;i+=2){
        if(vis[i]||vis[i^1]) continue;
        stk[0] = 0;
        if(dfs(i,i^1)){
            while(stk[0]) vis[stk[stk[0]--]] = 0;
            if(dfs(i^1,i)) { cout<<"NIE"<<endl;return 0; }
        }
    }
    for(int i=2;i<=2*n+1;i++) if(vis[i]) cout<<i-1<<endl;
    return 0;
}

