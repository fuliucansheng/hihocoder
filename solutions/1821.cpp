#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
ll a[maxn], dp[maxn], n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n), dp[0] = a[0];
    ll s = a[0];
    for(int i = 1; i < n; i++) {
        s += a[i], dp[i] = s - dp[i - 1];
        for(int k = 2; k <= 3 && i - k >= 0; k++) dp[i] = max(dp[i], s - dp[i - k]);
    }
    cout<<dp[n - 1]<<endl;
    return 0;
}
