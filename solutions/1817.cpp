#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 330;
ll a[maxn], b[maxn], c[maxn], dp[maxn][maxn], n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n, n *= 3;
    for(int i = 1; i <= n; i++) cin>>a[i]>>b[i]>>c[i];
    dp[1][0] = a[1], dp[0][1] = b[1], dp[0][0] = c[1];
    for(int i = 2; i <= n; i++) for(int j = i; j >= 0; j--) for(int k = i - j; k >= 0; k--) {
        dp[j][k] = dp[j][k] + c[i];
        if(j) dp[j][k] = max(dp[j][k], dp[j - 1][k] + a[i]);
        if(k) dp[j][k] = max(dp[j][k], dp[j][k - 1] + b[i]);
    }
    cout<<dp[n / 3][n / 3]<<endl;
    return 0;
}
