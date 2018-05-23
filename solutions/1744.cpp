#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    //freopen("../input.txt", "r", stdin);
    ll n, x, y, z; cin>>n>>x>>y>>z;
    ll ans = 0;
    if(y <= z) ans = n * z / x;
    else {
        ll k0 = (x - y) * n / (x - y + z);
        ll k1 = k0 + 1, k2 = k0 - 1;
        if(k0 >= 0) ans = max(ans, min(n - k0, z * k0 / (x - y)));
        if(k1 >= 0) ans = max(ans, min(n - k1, z * k1 / (x - y)));
        if(k2 >= 0) ans = max(ans, min(n - k2, z * k2 / (x - y)));
    }
    cout<<ans<<endl;
    return 0;
}
