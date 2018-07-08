#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, p;
ll pow_mod(ll x, ll y) {
    __int128 ret = 1, xx = x, yy = y;
    while(yy) {
        if(yy & 1) ret *= xx, ret %= __int128(p);
        yy >>= 1, xx *= xx, xx %= __int128(p);
    }
    return ll(ret);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>k>>p;
    cout<<pow_mod(k, n)<<endl;
    return 0;
}
