#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn = 35;
ll arr[maxn], dp[maxn], ans[maxn], p = 0;
pll rc[maxn];
void solve(ll l, ll r, ll K){
    if(l > r) return;
    if(l == r) { ans[p++] = arr[l]; return; }
    if(K == 0) K = 1;
    for(ll i=l;i<=r;i++) rc[i].first = arr[i], rc[i].second = -i;
    sort(rc + l, rc + r + 1);
    for(ll i=l;i<=r;i++){
        ll k = -rc[i].second;
        ll c = dp[k - l] * dp[r - k];
        if(c >= K){
            ans[p++] = arr[k];
            ll w = K / dp[r - k], v = K % dp[r - k];
            if(v == 0) solve(l, k-1, w), solve(k+1, r, dp[r - k]);
            else solve(l, k-1, w+1), solve(k+1, r, v);
            return;
        }else K -= c;
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    ll n, K; cin>>n>>K;
    for(ll i=0;i<n;i++) cin>>arr[i];
    dp[0] = dp[1] = 1;
    for(ll i=2;i<n+2;i++) for(ll j=0;j<i;j++) dp[i] += dp[j] * dp[i-j-1];
    solve(0, n-1, K);
    for(ll i=0;i<n;i++) cout<<ans[i]<<endl;
    return 0;
}
