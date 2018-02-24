#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010, mod = 998244353;
ll dp[32][2], rc[maxn], arr[maxn], n, ans = 0;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>arr[i];
    rc[0] = 1;
    for(ll i=1;i<=n;i++) rc[i] = (rc[i-1] * 2) % mod;
    for(ll i=0;i<32;i++) dp[i][0] = 1, dp[i][1] = 0;
    for(ll i=1;i<=n;i++){
        for(ll j=31;j>=0;j--) if((arr[i]>>j)&1){
                ans += dp[j][0] * rc[n-i], ans %= mod;
                break;
            }
        for(ll j=31;j>=0;j--){
            if((arr[i]>>j)&1){
                ll a = dp[j][0], b = dp[j][1];
                dp[j][0] = dp[j][1] = (a + b) % mod;
            }else{
                dp[j][0] = dp[j][0] * 2 % mod;
                dp[j][1] = dp[j][1] * 2 % mod;
            }
        }
    }
    cout<<(ans + mod) % mod<<endl;
    return 0;
}
