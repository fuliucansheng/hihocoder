#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 200010;
map<ll,ll> g;
ll arr[maxn], rc[maxn], cnt, n, k, t;
bool is_valid(ll x){
    memset(rc, 0, sizeof(rc));
    ll j = 0, tmp = 0;
    for(;j<n;j++) {
        if(tmp + rc[arr[j]] > x) break;
        tmp += rc[arr[j]], rc[arr[j]]++;
    }
    j--;
    ll tot = j + 1;
    for(ll i=1;i<n;i++){
        tmp -= rc[arr[i-1]] - 1, rc[arr[i-1]]--;
        for(j=j+1;j<n;j++){
            if(tmp + rc[arr[j]] > x) break;
            tmp += rc[arr[j]], rc[arr[j]]++;
        }
        j--; tot += j - i + 1;
    }
    return tot >= k;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>t;
    while(t--){
        cnt = 0, g.clear();
        cin>>n>>k;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(!g.count(arr[i])) g[arr[i]] = cnt++;
            arr[i] = g[arr[i]];
        }
        ll l = 0, r = n * (n + 1) / 2;
        while(r - l > 1){
            ll m = (l + r) / 2;
            if(is_valid(m)) r = m; else l = m;
        }
        cout<<(is_valid(l) ? l : r)<<endl;
    }
    return 0;
}
