#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1000010;
ll cc[maxn], vv[maxn], l, r;
bool vs[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    memset(vs, 0, sizeof(vs)); memset(cc, 0, sizeof(cc));
    vector<ll> pme;
    vs[0] = vs[1] = true;
    for(ll i = 2; i < 100000; i++) if(!vs[i]) {
        pme.push_back(i);
        for(ll j = i + i; j < 100000; j += i) vs[j] = true;
    }
    cin>>l>>r;
    for(ll i = l; i <= r; i++) vv[i - l] = i;
    for(auto p : pme) {
        if(p * p > r) break;
        for(ll i = (l + p - 1) / p * p; i <= r; i += p) while(vv[i - l] % p == 0) cc[i - l]++, vv[i - l] /= p;
    }
    int ans = 0;
    for(ll i = l; i <= r; i++) {
        if(vv[i - l] > 1) cc[i - l]++;
        if(!vs[cc[i - l]]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
