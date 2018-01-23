#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 100010, mod = 1000000007;
ll arr[maxn], n, k;
ll g(ll m){
    ll rs = 1, ds = 2;
    while(m){
        if(m&1) rs *= ds, rs %= mod;
        ds *= ds, ds %= mod, m >>= 1;
    }
    return rs >= 0 ? rs : rs + mod;
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    ll l = 0, r = n-1, rs = 0;
    while(l <= r) if(arr[l] + arr[r] <= k) rs += g(r-l), rs %= mod, l++; else r--;
    cout<<rs<<endl;
    return 0;
}

