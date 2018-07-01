#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    ll a, b, n; cin>>n>>a>>b;
    ll ans = 0;
    for(ll x = 1; x <= n; x++) {
        for(ll y = x; y ; y = ll(y - 1) & x) {
            ll x0 = ll(a * x + b * y), x1 = ll(a * y + b * x);
            ans = max(ans, x0 ^ x1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
