#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ps;
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}
ps extend_gcd(ll a, ll b){
    if(a%b == 0) return ps(0, 1);
    ps r = extend_gcd(b, a%b);
    return ps(r.second, r.first - (a/b)*r.second);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    ll s1, s2, v1, v2, m;
    cin>>s1>>s2>>v1>>v2>>m;
    ll v = v1 - v2, s = s2 - s1;
    if(v < 0) v += m;
    ll r = gcd(m, v);
    if(s%r) return cout<<-1<<endl, 0;
    ll nv = v/r, ns = s/r, nm = m/r;
    ps rs = extend_gcd(nv, nm);
    ll rr = (rs.first * ns)%nm;
    while(rr < 0) rr += nm;
    cout<<rr<<endl;
    return 0;
}
