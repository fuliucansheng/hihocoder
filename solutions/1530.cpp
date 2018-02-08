#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll extend_gcd(ll a, ll b, ll& x, ll& y){
    if(b == 0) return x = 1, y = 0, a;
    ll d = extend_gcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
int main() {
    //freopen("../input.txt", "r" , stdin);
    ll a, b, p, x, y; cin>>a>>b>>p;
    extend_gcd(b, p, x, y);
    x = (x + (abs(x) / p + 1) * p) % p;
    cout<<(a * x) % p<<endl;
    return 0;
}
