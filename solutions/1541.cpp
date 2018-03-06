#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> graph[maxn];
int fa[maxn][25], ht[maxn], n, m;
void dfs(int u, int f, int h){
    fa[u][0] = f, ht[u] = h;
    for(int i=1;i<20;i++) fa[u][i] = fa[fa[u][i-1]][i-1];
    for(auto v:graph[u]) if(v != f) dfs(v, u, h + 1);
}
int get_lca(int a, int b){
    if(ht[a] < ht[b]) swap(a, b);
    for(int i=19;i>=0;i--) if(ht[fa[a][i]] >= ht[b]) a = fa[a][i];
    if(a == b) return a;
    for(int i=19;i>=0;i--) if(ht[fa[a][i]] != ht[fa[b][i]]) a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}
bool is_valid(int x1, int y1, int x2, int y2){
    int t1 = get_lca(x1, y1), t2 = get_lca(x2, y2);
    int tt = get_lca(t1, t2);
    if(tt == t1)  if(get_lca(t2, x1) == t2 || get_lca(t2, y1) == t2) return true;
    if(tt == t2)  if(get_lca(t1, x2) == t1 || get_lca(t1, y2) == t1) return true;
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<=n;i++) graph[i].clear(); memset(fa, 0, sizeof(fa)); memset(ht, 0, sizeof(ht));
        for(int i=1;i<n;i++){
            int u, v; cin>>u>>v;
            graph[u].push_back(v), graph[v].push_back(u);
        }
        dfs(1, 1, 1);
        for(int i=0;i<m;i++){
            int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
            cout<<(is_valid(x1, y1, x2, y2) ? "YES" : "NO")<<endl;
        }
    }
    return 0;
}
