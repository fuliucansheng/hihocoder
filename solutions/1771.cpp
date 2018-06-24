#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(ll x) {
    ll ret = 0;
    while(x) ret += (x % 10) * (x % 10), x /= 10;
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    ll k, a, b; cin>>k>>a>>b;
    int ans = 0;
    for(ll i = 0; i <= 1458; i++) {
        ll x = k * i;
        if(calc(x) == i && x >= a && x <= b) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
