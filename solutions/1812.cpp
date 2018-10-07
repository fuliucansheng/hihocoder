#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 100010;
pll a[maxn];
int main(){
//    freopen("../input.txt", "r", stdin);
    ll n; cin>>n;
    for(ll i = 0, x, y, w; i < n; i++) {
        cin>>x>>y>>w;
        a[i].first = x * x + y * y, a[i].second = w;
    }
    sort(a, a + n);
    ll ret = 0, pre = 0;
    bool status = false;
    for(ll i = 0, j = 0; j <= n; j++) {
        if(j == n || a[j].first != a[i].first) {
            if(!status) ret = pre;
            ret = max(ret, pre), i = j;
            status = true;
        }
        pre += a[j].second;
    }
    cout<<ret<<endl;
    return 0;
}
