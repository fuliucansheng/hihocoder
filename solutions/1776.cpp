#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, p; cin>>n>>p;
    if(n >= p) return cout<<0<<endl, 0;
    ll ans = 1;
    for(int i = 1; i <= n; i++) ans *= (p - i), ans %= mod;
    cout<<ans<<endl;
    return 0;
}
