#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010, mod = 1000000009;
ll ra[maxn], rb[maxn], aa = 1, bb = 1, a, b, n, ans = 0;
ll xmod(ll a, ll b){
    ll r = 0;
    while(b){
        if(b&1) r += a, r %= mod;
        a <<= 1, a %= mod, b >>= 1;
    }
    return r;
}
ll extend_gcd(ll a, ll b, ll& x, ll& y){
    if(b == 0) return x = 1, y = 0, a;
    ll d = extend_gcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>a>>b;
    ra[0] = rb[0] = 1;
    for(ll i=1;i<=a;i++) aa *= i, aa %= mod;
    for(ll i=1;i<=b;i++) bb *= i, bb %= mod;
    for(ll i=1;i<max(a,b);i++) {
        ll x, _;
        extend_gcd(i, mod, x, _);
        x = (x + (abs(x) / mod + 1) * mod) % mod;
        if(i < a) ra[i] = xmod(xmod(ra[i-1], a - i), x);
        if(i < b) rb[i] = xmod(xmod(rb[i-1], b - i), x);
    }
    for(ll i=2;i<n;i++) if(i <= a && (n - i) <= b) ans += xmod(xmod(xmod(ra[i-1], aa), i-1), xmod(rb[n-i-1], bb)), ans %= mod;
    cout<<(ans + mod) % mod<<endl;
    return 0;
}
