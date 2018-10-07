#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int a[maxn], n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    ll ans = 0, h = 0;
    for(int i = 0; i < n; i++) cin>>a[i], ans += a[i];
    sort(a, a + n);
    for(int i = 0, j = 0; j <= n; j++) if(a[i] != a[j]) {
        ans -= (a[i] - h) * (n - i);
        h = a[i], i = j;
        cout<<ans<<endl;
    }
    return 0;
}
