#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 100010;
pll arr[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    int n, q; cin>>n>>q;
    for(int i = 0; i < n; i++) cin>>arr[i].first>>arr[i].second;
    sort(arr, arr + n);
    vector<pll> cov, rc, cnt;
    for(int i = 0; i < n; ) {
        ll p = arr[i].first, mx = arr[i].second;
        while(i < n && arr[i].first <= mx) mx = max(arr[i].second, mx), i++;
        if(cov.empty() && p > 1) rc.push_back(pll(1, p - 1));
        else if(!cov.empty() && cov.back().second < p - 1) rc.push_back(pll(cov.back().second + 1, p - 1));
        if(i == n) rc.push_back(pll(mx + 1, mx + 1));
        cov.push_back(pll(p, mx));
    }
    for(auto p:rc) {
        ll cc = p.second - p.first + 1;
        if(cnt.empty()) cnt.push_back(pll(p.first, cc));
        else cnt.push_back(pll(p.first, cc + cnt.back().second));
    }
    while(q--){
        ll k; cin>>k;
        ll l = 0, r = ll(cnt.size());
        while(r - l > 1) {
            ll m = (l + r) / 2;
            if(cnt[m].second >= k) r = m;
            else l = m;
        }
        ll x = (cnt[l].second >= k ? l : r);
        if(x != ll(cnt.size())) {
            cout<<cnt[x].first + k - (x ? cnt[x - 1].second : 0) - 1<<endl;
        }else{
            cout<<cnt.back().first + k - (cnt.empty() ? 0 : cnt.back().second)<<endl;
        }
    }
    return 0;
}
