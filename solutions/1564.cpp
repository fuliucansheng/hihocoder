#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 100010;
vector<ll> graph[maxn];
pll rc[maxn];
ll arr[maxn], fa[maxn], n;
void dfs(int u){
    ll rs = 0, mx = 0;
    for(auto v:graph[u]) dfs(v), mx = max(mx, rc[v].second);
    for(auto v:graph[u]) rs += rc[v].first + mx - rc[v].second;
    rc[u] = pll(rs, mx + arr[u]);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    memset(arr, 0, sizeof(arr)); memset(fa, 0, sizeof(fa));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        ll u, v; cin>>u>>v;
        fa[v] = u, graph[u].push_back(v);
    }
    for(int i=1;i<=n;i++) if(fa[i] == 0){
            dfs(i), cout<<rc[i].first<<endl;
            break;
        }
    return 0;
}
