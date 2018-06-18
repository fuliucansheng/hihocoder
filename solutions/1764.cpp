#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 55;
ll a[maxn], n;
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    ll x = 0;
    for(int i = 0; i < n; i++) cin>>a[i], x ^= a[i];
    if(x != 0) cout<<0<<endl;
    else {
        ll ans = 1;
        for(int i = 0; i < n; i++) ans *= 2;
        cout<<ans - 2<<endl;
    }
    return 0;
}
