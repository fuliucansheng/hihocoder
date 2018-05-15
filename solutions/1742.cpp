#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
vector<int> graph[maxn];
ll sz[maxn], ds[maxn], ans[maxn], n;
void dfs1(int u, int fa) {
    sz[u] = 1, ds[u] = 0;
    for(auto v : graph[u]) if(v != fa) {
        dfs1(v, u);
        sz[u] += sz[v], ds[u] += sz[v] + ds[v];
    }
}
void dfs2(int u, int fa) {
    if(fa) ans[u] = ans[fa] - sz[u] + n - sz[u];
    else ans[u] = ds[u];
    for(auto v : graph[u]) if(v != fa) dfs2(v, u);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i = 1; i < int(n); i++) {
        int a, b; cin>>a>>b;
        graph[a].push_back(b), graph[b].push_back(a);
    }
    memset(ans, 0, sizeof(ans));
    dfs1(1, 0), dfs2(1, 0);
    for(int i = 1; i <= int(n); i++) cout<<ans[i]<<endl;
    return 0;
}
