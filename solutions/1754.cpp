#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
ll a[maxn], n, c;
ll dfs(ll x, ll v) {
    if(x == 0) return 1 + (a[x] <= v);
    if(2 * a[x] <= v) return ll(pow(2, x + 1));
    ll ret = dfs(x - 1, v);
    if(a[x] <= v) ret += dfs(x - 1, v - a[x]);
    return ret;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n>>c;
    for(ll i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);
    ll ans = dfs(n - 1, c);
    cout<<ans - 1<<endl;
    return 0;
}
