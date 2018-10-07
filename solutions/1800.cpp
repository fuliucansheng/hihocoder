#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3f;
const ll maxn = 310;
ll a[maxn][maxn], pre[maxn][maxn], n, m, s;
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m>>s;
    memset(pre, 0, sizeof(pre));
    for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) cin>>a[i][j], pre[i][j] = pre[i - 1][j] + a[i][j];
    ll ans = -inf;
    for(ll i = 1; i <= n; i++) for(ll j = i; j <= n; j++) {
        ll su = 0, pp = 0, mn = 0, d = j - i + 1, x = 1;
        while(x <= m && x * d < s) su += pre[j][x] - pre[i - 1][x], x++;
        for(ll k = x; k <= m; k++) {
            su += pre[j][k] - pre[i - 1][k];
            pp += pre[j][k - x] - pre[i - 1][k - x];
            mn = min(pp, mn);
            ans = max(ans, su - mn);
        }
    }
    cout<<ans<<endl;
    return 0;
}


