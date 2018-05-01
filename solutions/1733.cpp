#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int a[101][10010], n, m;
ll dp[2][10010];
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
        sort(a[i], a[i] + m);
    }
    memset(dp, 0, sizeof(dp));
    for(int i = m - 1; i >= 0; i--) dp[1][i] = m - i;
    for(int i = n - 2; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) dp[0][j] = dp[1][upper_bound(a[i + 1], a[i + 1] + m, a[i][j]) - a[i + 1]];
        for(int j = m - 1; j >= 0; j--) dp[1][j] = dp[0][j] + dp[1][j + 1], dp[1][j] %= mod;
    }
    cout<<dp[1][0]<<endl;
    return 0;
}
