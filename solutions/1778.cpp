#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, b, pre = 0;
int main(){
    //freopen("../input.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n>>a>>b;
    if(a > 0) {
        ll mx = 0, mn = 0;
        for(ll i = 0, x; i < n; i++) {
            cin>>x;
            pre += x;
            mx = max(mx, pre - mn);
            mn = min(mn, pre);
        }
        cout<<a * mx + b<<endl;
    } else if(a < 0) {
        ll mx = 0, mn = 0;
        for(ll i = 0, x; i < n; i++) {
            cin>>x;
            pre += x;
            mn = min(mn, pre - mx);
            mx = max(mx, pre);
        }
        cout<<a * mn + b<<endl;
    } else {
        for(ll i = 0, x; i < n; i++) cin>>x;
        cout<<b<<endl;
    }
    return 0;
}
