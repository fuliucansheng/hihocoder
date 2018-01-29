#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010;
ll arr[20][maxn], p[maxn], n;
void add(ll x, ll y, ll a[]){
    while(x) a[x] += y, x -= (x&(-x));
}
ll get(ll x, ll a[]){
    ll r = 0;
    while(x < maxn) r += a[x], x += (x&(-x));
    return r;
}
int main() {
    //freopen("../input.txt", "r" , stdin);
    memset(arr, 0, sizeof(arr)); memset(p, 0, sizeof(p));
    cin>>n;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll num; cin>>num;
        ll r = get(num+1, p);
        for(ll j=0;j<20;j++){
            if(num>>j&1) ans += ll(1 << j) * (r - get(num+1, arr[j]));
            else ans += ll(1 << j) * get(num+1, arr[j]);
            if(num>>j&1) add(num, 1, arr[j]);
        }
        add(num, 1, p);
    }
    cout<<ans<<endl;
    return 0;
}
