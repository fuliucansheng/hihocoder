#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010;
ll c[maxn], d[maxn], n, k;
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    cin>>n>>k;
    for(ll i=0;i<n;i++) cin>>c[i];
    sort(c, c + n);
    for(ll i=1;i<n;i++) d[i] = c[i] - c[i-1];
    sort(d + 1, d + n);
    ll ans = 0;
    for(ll i=1;i<min(n-k+1, n);i++) ans += d[i];
    cout<<ans<<endl;
    return 0;
}
