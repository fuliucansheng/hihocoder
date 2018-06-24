#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 200010;
ll a[maxn], n, s, pre = 0;
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>s;
    map<ll,ll> mp;
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        cin>>a[i], pre = a[i] + pre;
        ll low = pre - s;
        auto it = mp.lower_bound(low);
        if(pre <= s) ans = max(ans, i);
        if(it != mp.end()) ans = max(ans, i - it->second);
        if(!mp.count(pre)) {
            auto pt = mp.insert({pre, i});
            it = pt.first, it++;
            if(it != mp.end()) mp[pre] = it->second;
        }
    }
    cout<<(ans ? ans : -1)<<endl;
    return 0;
}
