#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 1010;
ll a[maxn], sz[maxn], n, k;
vector<pll> graph[maxn];
vector<ll> vec;
ll dfs(ll u, ll f) {
    ll ret = 0;
    for(auto p : graph[u]) if(p.first != f) {
            ret += dfs(p.first, u);
            ll cos = sz[p.first] * p.second;
            vec.push_back(cos), ret += cos, sz[u] += sz[p.first];
        }
    sz[u] += a[u];
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>k;
    for(ll i = 1; i <= n; i++) cin>>a[i];
    for(ll i = 1; i < n; i++) {
        ll u, v, w; cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(ll i = 1; i <= n; i++) {
        memset(sz, 0, sizeof(sz)), vec.clear();
        ll ret = dfs(i, 0);
        sort(vec.begin(), vec.end(), greater<ll>());
        for(ll j = 0; j < k; j++) ret -= vec[j];
        ans = min(ans, ret);
    }
    cout<<ans<<endl;
    return 0;
}
