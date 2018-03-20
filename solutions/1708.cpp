#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, x, y, a, b, c, d;
ll cnt(ll aa, ll bb){
    if(aa == 0 && bb == 0) return 1;
    ll ra = 0x3f3f3f3f3f3f3f3f, rb = 0x3f3f3f3f3f3f3f3f;
    if(aa != 0) {
        if(aa > 0) ra = (n - x) / aa + 1;
        else ra = (x - 1) / abs(aa) + 1;
    }
    if(bb != 0) {
        if(bb > 0) rb = (m - y) / bb + 1;
        else rb = (y - 1) / abs(bb) + 1;
    }
    return min(ra, rb);
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m>>x>>y>>a>>b>>c>>d;
    ll ans = cnt(a, b) + cnt(c, d) - 1;
    if(a * d == b * c){
        ll dd, ac = 0, bd = 0;
        if(b != 0 && d != 0) dd = __gcd(b, d), ac = b / dd * c, bd = b / dd * d;
        if(a != 0 && c != 0) dd = __gcd(a, c), ac = a / dd * c, bd = a / dd * d;
        ans = ans - cnt(ac, bd) + 1;
    }
    cout<<ans<<endl;
    return 0;
}
