#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010;
vector<ll> graph[maxn];
ll va[maxn], fa[maxn], d[maxn], n, rt, sum, ans;
void dfs(ll u){
    for(auto v:graph[u]) dfs(v), va[u] += va[v], ans += d[u] * d[v], d[u] += d[v];
    if(u != rt && va[u] == (2 * sum / 3)) ans += d[u];
    if(va[u] == (sum / 3)) d[u]++;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        for(ll i=0;i<maxn;i++) graph[i].clear();
        memset(d, 0, sizeof(d));
        cin>>n;
        sum = 0;
        for(ll i=1;i<=n;i++) {
            cin>>va[i]>>fa[i];
            if(fa[i] == 0) rt = i;
            sum += va[i], graph[fa[i]].push_back(i);
        }
        if(sum % 3 != 0) cout<<0<<endl;
        else{
            ans = 0, dfs(rt);
            cout<<ans<<endl;
        }
    }
}
