#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010, mod = 1000000007;
ll arr[maxn], pre[maxn], dp[maxn], n, sum = 0;
int main() {
    //freopen("../input.txt", "r", stdin);
    memset(dp, 0, sizeof(dp)); memset(pre, 0, sizeof(pre));
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i], pre[i] = (i > 0 ? pre[i-1] : 0) + arr[i];
    ll sum = 0;
    map<ll,ll> dict;
    for(int i=0;i<n;i++) {
        if(pre[i]) dp[i] = 1;
        dp[i] += (sum - dict[pre[i]] + mod) % mod, dp[i] %= mod;
        dict[pre[i]] += dp[i], dict[pre[i]] %= mod;
        sum += dp[i], sum %= mod;
    }
    cout<<dp[n-1]<<endl;
}
