#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1010, mod = 1000000007;
ll dp[maxn][maxn], n;
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for(int i=2;i<=n;i++) for(int j=1;j<=i;j++) dp[i][j] += (dp[i-1][j-1] + dp[i-1][j]) * j, dp[i][j] %= mod;
    ll ans = 0;
    for(int i=0;i<=n;i++) ans += dp[n][i], ans %= mod;
    cout<<(ans + mod) % mod<<endl;
    return 0;
}
