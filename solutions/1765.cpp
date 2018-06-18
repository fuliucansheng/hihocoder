#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 15;
int a[maxn], b[maxn], n;
ll dp[maxn][1<<maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    for(int i = 0; i < n; i++) if(b[i] >= a[0]) dp[0][1<<i] = 1;
    for(int i = 0; i + 1 < n; i++) for(int j = 0; j < (1 << n); j++) if(dp[i][j]) {
        for(int k = 0; k < n; k++) if((j & (1 << k)) == 0 && b[k] >= a[i + 1]) dp[i + 1][j | (1 << k)] += dp[i][j];
    }
    cout<<dp[n - 1][(1 << n) - 1]<<endl;
    return 0;
}
