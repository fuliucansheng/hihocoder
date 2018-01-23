#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;
vector<int> graph[maxn];
int fa[maxn], n, k;
void dfs(int u, int f){
    fa[u] = f;
    for(auto v:graph[u]) if(v != f) dfs(v, u);
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    dfs(k, 0);
    for(int i=1;i<=n;i++) cout<<fa[i]<<" "; cout<<endl;
    return 0;
}

