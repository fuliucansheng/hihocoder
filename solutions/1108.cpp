#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 10010;
int vis[maxn<<1], cpy[maxn<<1], m, n;
vector<int> graph[maxn<<1];
bool dfs(int u){
    if(vis[u^1]) return false;
    vis[u] = 1;
    for(auto v:graph[u]) if(!vis[v] && !dfs(v)) return false;
    return true;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<(maxn<<1);i++) graph[i].clear();
        int a, b, s; cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>a>>b>>s;
            if(s == 0) graph[2*a].push_back(2*b+1), graph[2*b].push_back(2*a+1);
            else graph[2*a+1].push_back(2*b), graph[2*b+1].push_back(2*a);
        }
        bool rs = true;
        for(int i=1;i<=n;i++){
            if(!vis[2*i] && !vis[2*i+1]){
                memcpy(cpy, vis, sizeof(vis));
                if(!dfs(2*i)){
                    memcpy(vis, cpy, sizeof(vis));
                    if(!dfs(2*i+1)) { rs = false; break; }
                }
            }
        }
        cout<<(rs ? "Yes" : "No")<<endl;
    }
    return 0;
}
