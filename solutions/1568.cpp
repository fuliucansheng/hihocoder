#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 305, mod = 1000000007;
ll dp[2][maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    ll n, k; cin>>n>>k;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(ll i=0;i<(n<<1);i++) {
        memset(dp[(i+1)%2], 0, sizeof(dp[0]));
        for(ll a=0;a<=min(i,n);a++) for(ll b=0;b<=a;b++) if(dp[i%2][a][b]){
                    dp[(i+1)%2][a+1][b+1] += dp[i%2][a][b], dp[(i+1)%2][a+1][b+1] %= mod;
                    dp[(i+1)%2][a][max(b-1,ll(0))] += dp[i%2][a][b], dp[(i+1)%2][a][max(b-1,ll(0))] %= mod;
                }
    }
    cout<<(dp[0][n][k] + mod) % mod<<endl;
    return 0;
}
