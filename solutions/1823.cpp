#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010;
ll fa[maxn], dd[maxn], ds[maxn], cc[maxn], n, m;
bool st[maxn];
void upd(ll x) {
    if(st[x]) return;
    st[x] = true;
    ll d = 0, p = x, c0 = cc[0] + 1;
    stack<ll> stk;
    while(p) {
        stk.push(p), cc[p]++;
        d += ds[p], p = fa[p];
    }
    cc[0]++, dd[0] += d;
    while(!stk.empty()) {
        ll t = stk.top(); stk.pop();
        ll ft = fa[t];
        dd[t] = dd[ft] - ds[t] * cc[t] + (c0 - cc[t]) * ds[t];
    }
}
ll query(ll x) {
   ll p = x, c0 = cc[0];
   stack<ll> stk;
   while(p) stk.push(p), p = fa[p];
   while(!stk.empty()) {
        ll t = stk.top(); stk.pop();
        ll ft = fa[t];
        dd[t] = dd[ft] - ds[t] * cc[t] + (c0 - cc[t]) * ds[t];
   }
   return dd[x];
}
int main(){
//    freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(ll i = 1; i < n; i++) cin>>fa[i];
    for(ll i = 1; i < n; i++) cin>>ds[i];
    for(ll i = 0, t, x; i < m; i++) {
        cin>>t>>x;
        if(t == 1) upd(x);
        if(t == 2) cout<<query(x)<<endl;
    }
    return 0;
}
