#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 205, mod = 1e9+7;
ll p0[maxn], p1[maxn], dp[maxn][maxn][maxn], ans = 0, n;
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>p1[i], p0[i] = 1000 - p1[i];
    memset(dp, 0, sizeof(dp));
    dp[1][1][0] = p0[1]; dp[1][0][1] = p1[1];
    for(ll i=1;i<n;i++) for(ll j=0;j<=i;j++) for(ll k=0;k<=i;k++) {
                dp[i+1][j+1][k] += dp[i][j][k]*p0[i+1];
                dp[i+1][j][max(k+1, j+1)] += dp[i][j][k]*p1[i+1];
                dp[i+1][j+1][k] %= mod, dp[i+1][j][max(k+1, j+1)] %= mod;
            }
    for(ll i=0;i<=n;i++) for(ll j=0;j<=n;j++) ans += max(i,j)*dp[n][i][j], ans %= mod;
    cout<<ans<<endl;
    return 0;
}
