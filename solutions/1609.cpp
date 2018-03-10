#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 100010, mod = 1000000007;
ll arr[maxn], pos[maxn], n;
pll dp[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    memset(arr, -1, sizeof(arr)); memset(pos, -1, sizeof(pos));
    for(ll i=0;i<maxn;i++) dp[i].first = 0, dp[i].second = 0;
    cin>>n;
    for(ll i=0;i<n;i++) cin>>arr[i];
    ll p = -1;
    for(ll i=0;i<n;i++){
        p = max(p, pos[arr[i]]);
        if(p == -1) dp[i].first = 1, dp[i].second = 1;
        else for(ll j=p;j<i;j++) if(dp[j].first == dp[p].first) dp[i].first = dp[j].first + 1, dp[i].second += dp[j].second, dp[i].second %= mod;
        pos[arr[i]] = i;
    }
    cout<<dp[n-1].first<<" "<<(dp[n-1].second + mod) % mod<<endl;
    return 0;
}
