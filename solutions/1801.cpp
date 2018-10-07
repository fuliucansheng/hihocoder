#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, p;
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n>>k>>p;
    if(n == k) return cout<<1<<endl, 0;
    if(n == k + 1) return cout<<n % p<<endl, 0;
    ll ans = 1;
    for(ll i = (k & 1) ? 2 : 3; i <= n; i++) ans *= i, ans %= p;
    cout<<ans<<endl;
    return 0;
}
