#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    stack<ll> stk;
    ll n; cin>>n;
    map<ll,ll> mp;
    ll p = 0;
    for(ll i = 0, x; i < n; i++) {
        string op; cin>>op;
        if(op == "push") {
            cin>>x;
            mp[stk.size()] += p, p = 0;
            stk.push(x);
        } else if(op == "inc") {
            ll k; cin>>k>>x;
            mp[k] += x;
        } else if(op == "pop") {
            ll sz = ll(stk.size()), val = stk.top(); stk.pop();
            p += mp[sz], mp[sz] = 0;
            cout<<val + p<<endl;
        }
    }
    return 0;
}
