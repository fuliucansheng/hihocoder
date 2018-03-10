#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 1010;
ll dp[maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    ll n, m; cin>>n>>m;
    map<ll,ll> cnt;
    for(int i=0;i<n;i++) {
        ll a; cin>>a;
        cnt[a]++;
    }
    vector<pll> rc;
    for(auto p:cnt) rc.push_back(pll(p.first, p.first * p.second));
    memset(dp, 0, sizeof(dp));
    dp[0][1] = rc[0].second;
    ll ans = dp[0][1];
    for(ll i=1;i<int(rc.size());i++) for(ll j=1;j<=i;j++){
            dp[i][j] = dp[i-1][j];
            if((rc[i].first - rc[i-1].first) > ll(1)) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + rc[i].second);
            else if(i > 1) dp[i][j] = max(dp[i][j], dp[i-2][j-1] + rc[i].second);
            else if(j == 1) dp[i][j] = max(dp[i][j], rc[i].second);
            if(j <= m) ans = max(ans, dp[i][j]);
        }
    cout<<ans<<endl;
    return 0;
}
