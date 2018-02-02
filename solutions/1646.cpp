#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll pw[1010], n;
string s[30];
int main() {
    //freopen("../input.txt", "r" , stdin);
    pw[0] = 1;
    for(int i=1;i<1010;i++) pw[i] = 2 * pw[i-1], pw[i] %= mod;
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    ll sz = 1, ssz = 0;
    for(int i=0;i<n;i++) {
        sz += ll(s[i].size());
        for(auto c:s[i]) if(c == '?') ssz++;
    }
    ll ans = sz * pw[ssz] % mod;
    for(ll i=1;i<(ll(1)<<n);i++){
        vector<ll> rc;
        for(ll j=0;j<n;j++) if(i>>j&1) rc.push_back(j);
        ll rz = ll(rc.size());
        if(rz <= 1) continue;
        ll mnl = ll(1)<<30;
        for(ll j=0;j<rz;j++) mnl = min(mnl, ll(s[rc[j]].size()));
        ll tot = ssz;
        for(ll j=0;j<mnl;j++){
            ll num = 0, chac = -1;
            for(ll k=0;k<rz;k++){
                if(s[rc[k]][j] == '?') num++;
                else if(chac == -1) chac = s[rc[k]][j];
                else if(chac != s[rc[k]][j]) { chac = -2; break; }
            }
            if(chac == -2) break;
            if(chac == -1) tot -= num - 1;
            else tot -= num;
            ll v = pw[tot];
            if(rz % 2 == 0) v = mod - v;
            ans += v, ans %= mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
