#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1010;
ll arr[maxn], n;
ll cnt(double l, double r, ll k){
    ll c = 0;
    for(int i=0;i<n;i++){
        double a = l * arr[i], b = r * arr[i];
        ll aa = ceil(a) + (a == 0), bb = floor(b);
        c += bb - aa + (double(bb) < b);
        if(c >= k) return -1;
    }
    return c;
}
int main() {
    //freopen("../input.txt", "r" , stdin);
    ll k; cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    double l = 0, r = 1;
    while(k > 1){
        double m = (l + r) / 2;
        ll rs = cnt(l, m, k);
        if(rs == -1) r = m;
        else k -= rs, l = m;
    }
    ll a = 1, b = 1;
    for(int i=0;i<n;i++){
        double c = l * arr[i], d = r * arr[i];
        ll cc = ceil(c) + (c == 0), dd = floor(d);
        if((dd - cc + (double(dd) < d)) > 0 && (a * arr[i] > b * cc)) a = cc, b = arr[i];
    }
    cout<<a<<"/"<<b<<endl;
    return 0;
}
