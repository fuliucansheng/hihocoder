#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  pair<ll,ll> pll;
const ll maxn = 500010;
pll pnt[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    ll m, n; cin>>n>>m;
    for(int i=0;i<n;i++) cin>>pnt[i].first>>pnt[i].second;
    for(int i=0;i<m;i++){
        ll a, b, r; cin>>a>>b>>r;
        ll ans = 0;
        for(int j=0;j<n;j++) if(((a-pnt[j].first)*(a-pnt[j].first) + (b-pnt[j].second)*(b-pnt[j].second)) <= r*r) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
