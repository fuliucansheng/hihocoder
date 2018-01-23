#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 305;
ll arr[maxn][maxn], r[maxn][maxn], c[maxn], m, n, k;
pll rec[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(arr, 0, sizeof(arr)); memset(r, 0, sizeof(r)); memset(c, 0, sizeof(c));
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) cin>>arr[i][j], r[i][j] = r[i-1][j] + arr[i][j];
    ll ans = -1;
    for(ll i=1;i<=n;i++) for(ll ii=i;ii<=n;ii++){
            for(ll j=1;j<=m;j++) c[j] = c[j-1] + r[ii][j] - r[i-1][j];
            ll rc = 0;
            rec[rc] = pll(-1000000000000000000, 0);
            for(ll j=1;j<=m;j++){
                while(c[j] <= rec[rc].first) rc--;
                rec[++rc] = pll(c[j], j);
            }
            ll l = 1;
            for(ll j=0;j<m;j++){
                if(rec[l].second == j) l++;
                ll cur = c[j] + k;
                ll p = upper_bound(rec + l, rec + 1 + rc, pll(cur, ll(1000000))) - rec; p--;
                if(p >= l && p <= rc) ans = max(ans, (rec[p].second - j)*(ii - i + 1));
            }
        }
    cout<<ans<<endl;
    return 0;
}
