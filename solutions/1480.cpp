#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll frac[501111], rev[501111];
int n, m;
ll fast_mod(ll x, ll y) {
    if (y == 0) return 1;
    ll ret = fast_mod(x, y >> 1);
    ret = ret * ret % mod;
    return y & 1 ? ret * x % mod : ret;
}

int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    frac[0] = 1;
    for (int i = 1;i <= 300000;i++) frac[i] = frac[i-1] * i % mod;
    for (int i = 0;i <= m * 3;i++) rev[i] = fast_mod(frac[i], mod-2);
    if (n == 1) cout<<1<<endl;
    if (n == 2) cout<<(frac[m<<1] * rev[m] % mod * rev[m] % mod * fast_mod(m+1, mod-2) % mod)<<endl;
    if (n == 3) cout<<(frac[m*3] * 2%mod * fast_mod(frac[m] * frac[m+1]%mod * frac[m+2]%mod, mod-2)%mod)<<endl;
}
