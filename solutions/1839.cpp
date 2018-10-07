#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5000010;
bool vs[maxn];
ll pow_mod(ll x, ll y, ll m) {
    ll ret = 1;
    while(y) {
        if(y & 1) ret *= x, ret %= m;
        y >>= 1, x *= x, x %= m;
    }
    return (ret + m) % m;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(vs, 0, sizeof(vs));
    for(int i = 2; i < maxn; i++) if(!vs[i]) for(int j = i + i; j < maxn; j += i) vs[j] = true;
    string s; cin>>s;
    ll ps = s[0] - '0', n = ll(s.size());
    for(int i = 1; i < s.size(); i++) ps += s[i] - '0';
    if(ps % 2 == 0) return cout<<2<<endl, 0;
    if(ps % 3 == 0 || n % 3 == 0) return cout<<3<<endl, 0;
    for(ll i = 4; i < maxn; i++) if(!vs[i] && (ps % i == 0 || pow_mod(10, n, i) == 1)) return cout<<i<<endl, 0;
    return 0;
}
