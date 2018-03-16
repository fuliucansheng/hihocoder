#include <bits/stdc++.h>
using namespace std;
#define cc(x) ((x + 1) * x / 2)
typedef long long ll;
unordered_set<ll> pm;
vector<ll> arr;
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    ll a, b; cin>>a>>b;
    for(ll i=1;i<=100000;i++){
        ll x = i, p = 1, h = 0;
        while(x) h *= 10, h += x % 10, x /= 10, p *= 10;
        ll r1 = i * p + h, r2 = i / 10 * p + h;
        if(!pm.count(r1)) pm.insert(r1), arr.push_back(r1);
        if(!pm.count(r2)) pm.insert(r2), arr.push_back(r2);
    }
    sort(arr.begin(), arr.end());
    ll sx = ll(lower_bound(arr.begin(), arr.end(), a) - arr.begin()), ex = ll(upper_bound(arr.begin(), arr.end(), b) - arr.begin());
    ll ans = 0;
    if(arr[sx] > b) ans += cc((b - a + 1));
    else {
        ans += cc((arr[sx] - a));
        ll cnt[2] = { arr[sx] - a + 1, 0 }, c = 1;
        for(ll i=sx;i<ex;i++){
            ans += cnt[c] * (min(arr[i+1], b+1) - arr[i]) + cc((min(arr[i+1], b + 1) - arr[i] - 1));
            cnt[c] += arr[i+1] - arr[i];
            c ^= 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
