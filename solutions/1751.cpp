#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1000010, mod = 1000000007;
ll dp[maxn], fct[maxn], inv[maxn];
ll pow_mod(ll x, ll y) {
    ll ret = 1;
    while(y) {
        if(y & 1) ret *= x, ret %= mod;
        y >>= 1, x *= x, x %= mod;
    }
    return ret;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 0, dp[1] = 1, fct[0] = 1;
    for(int i = 1; i <= n; i++) fct[i] = i * fct[i - 1], fct[i] %= mod, inv[i] = pow_mod(fct[i], mod - 2);
    ll sum = (dp[0] * inv[0] + dp[1] * inv[1]) % mod;
    for(int i = 2; i <= n; i++) {
        dp[i] = (sum + i) * fct[i - 1] % mod;
        sum += dp[i] * inv[i] % mod, sum %= mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
