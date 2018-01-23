#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1010, maxm = 5050;
vector<pair<int,int>> graph[maxn];
bool vis[maxm];
int m, n, pz = 0, pt[maxm],deg[maxn];
void dfs(int u){
    for(auto p:graph[u]) if(!vis[p.first]) vis[p.first] = true, deg[u]--, deg[p.second]--, dfs(p.second);
    pt[pz++] = u;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(vis, 0, sizeof(vis));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(make_pair(i,v)), graph[v].push_back(make_pair(i,u));
        deg[u]++, deg[v]++;
    }
    for(int i=1;i<=n;i++) if(deg[i]) dfs(i);
    for(int i=0;i<pz;i++) cout<<(i != 0 ? " " : "")<<pt[i];cout<<endl;
    return 0;
}
