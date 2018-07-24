#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
ll calc(ll x, ll y) {
    ll a = min(x, y), b = max(x, y);
    return a * (a + 1) * (3 * b - a + 1) / 6;
}
ll psum(ll x, ll y) {
    ll x0 = x - 1, y0 = y - 1, x1 = x0 + n, y1 = y0 + m;
    return calc(x0, y0) + calc(x1, y1) - calc(x0, y1) - calc(x1, y0);
}
ll extend_gcd(ll a, ll b, ll& x, ll& y){
    if(b == 0) return x = 1, y = 0, a;
    ll d = extend_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int q; cin>>q;
    while(q--) {
        cin>>n>>m>>k;
        ll ax = INT32_MAX, ay = INT32_MAX;
        ll lmt = max(n, m), nm = (n * m) % k, x, y;
        ll d = extend_gcd(nm, k, x, y);
        ll dd = k / d;
        for(ll i = 1; i <= lmt; i++) {
            ll a0 = psum(i, 1), r0 = k - (a0 % k), a1 = psum(1, i), r1 = k - (a1 % k);
            if(r0 % d == 0) {
                ll xx = r0 / d * x;
                xx = (xx + (abs(xx) / dd + 1) * dd) % dd;
                ll xp = i + xx, yp = 1 + xx;
                if(xp + yp < ax + ay || ((xp + yp) == (ax + ay) && ax > xp)) ax = xp, ay = yp;
            }
            if(r1 % d == 0) {
                ll xx = r1 / d * x;
                xx = (xx + (abs(xx) / dd + 1) * dd) % dd;
                ll xp = 1 + xx, yp = i + xx;
                if(xp + yp < ax + ay || ((xp + yp) == (ax + ay) && ax > xp)) ax = xp, ay = yp;
            }
        }
        if(ax == INT32_MAX) cout<<-1<<endl;
        else cout<<ax<<" "<<ay<<endl;
    }
    return 0;
}
