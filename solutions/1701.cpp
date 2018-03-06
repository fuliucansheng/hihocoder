#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 105, mod = 1000000009;
ll arr[maxn], dp[maxn][maxn], n, m, K;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m>>K;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++) dp[i][1] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++) if((arr[i] - arr[j]) % K == 0) {
                for(int k=0;k<n;k++) dp[i][k+1] += dp[j][k], dp[i][k+1] %= mod;
            }
    }
    ll ans = 0;
    for(int i=0;i<n;i++) ans += dp[i][m], ans %= mod;
    cout<<(ans + mod) % mod<<endl;
    return 0;
}
