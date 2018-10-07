#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1010, mod = 1000000007;
ll dp[maxn][2][3];
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n; cin>>n;
    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = 9, dp[1][0][1] = 1;
    for(int i = 1; i < n; i++) {
        if(dp[i][0][0]) dp[i + 1][0][0] += 9 * dp[i][0][0], dp[i + 1][0][1] += dp[i][0][0];
        if(dp[i][0][1]) dp[i + 1][0][0] += 9 * dp[i][0][1], dp[i + 1][0][2] += dp[i][0][1];
        if(dp[i][0][2]) dp[i + 1][0][0] += 9 * dp[i][0][2], dp[i + 1][1][2] += dp[i][0][2];
        if(dp[i][1][0]) dp[i + 1][1][0] += 9 * dp[i][1][0], dp[i + 1][1][1] += dp[i][1][0];
        if(dp[i][1][1]) dp[i + 1][1][0] += 9 * dp[i][1][1], dp[i + 1][1][2] += dp[i][1][1];
        if(dp[i][1][2]) dp[i + 1][1][0] += 9 * dp[i][1][2];
        for(int a = 0; a < 2; a++) for(int b = 0; b < 3; b++) dp[i + 1][a][b] %= mod;
    }
    ll ans = 0;
    for(int i = 0; i < 3; i++) ans += dp[n][1][i], ans %= mod;
    cout<<(ans + mod) % mod<<endl;
    return 0;
}
