#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1<<20], n, k;
vector<ll> pme;
ll cnt(ll m){
    ll g = 0, rs = m;
    arr[++g] = 1;
    for(ll i=0;i<ll(pme.size());i++){
        ll t = g;
        for(ll j=1;j<=g;j++) arr[++t] = pme[i] * arr[j] * -1, rs += m / arr[t];
        g = t;
    }
    return rs;
}
int main() {
    //freopen("../input.txt", "r" , stdin);
    cin>>n>>k;
    ll b = n;
    for(ll i=2;i*i<=b;i++)
        if(b%i == 0) {
            pme.push_back(i);
            while(b%i == 0) b /= i;
        }
    if(b > 1) pme.push_back(b);
    ll l = 1, r = n, ans = 1;
    while(l <= r){
        ll m = (l + r) / 2;
        if(cnt(m) >= k) r = m - 1, ans = m;
        else l = m + 1;
    }
    cout<<ans<<endl;
    return 0;
}
