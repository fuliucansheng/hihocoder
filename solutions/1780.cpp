#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
ll a[maxn], b[maxn], m, n;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    for(int tt = 1; tt <= t; tt++) {
        cin>>n>>m;
        for(ll i = 0; i < n; i++) cin>>a[i];
        for(ll i = 0; i < m; i++) cin>>b[i];
        sort(a, a + n); sort(b, b + m);
        ll a1 = max({a[n - 2], a[n - 2] * b[0], a[n - 2] * b[m - 1], a[0] * b[0], a[0] * b[m - 1]});
        ll a2 = max({a[n - 1], a[n - 1] * b[0], a[n - 1] * b[m - 1], a[1] * b[0], a[1] * b[m - 1]});
        cout<<"Case #"<<tt<<": "<<min(a1, a2)<<endl;
    }
    return 0;
}
