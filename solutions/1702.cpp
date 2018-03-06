#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 101;
int arr[maxn][maxn], dp[maxn][maxn][20][2], n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    memset(dp, inf, sizeof(dp));
    dp[0][0][0][0] = 0, dp[0][0][0][1] = 0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int a=0;a<20;a++){
                dp[i+1][j][a][1] = min(dp[i+1][j][a][1], dp[i][j][a][1] + arr[i][j]);
                if(a > 0) dp[i+1][j][a][1] = min(dp[i+1][j][a][1], dp[i][j][a-1][0] + arr[i][j] + int(pow(2, a - 1)));
                dp[i][j+1][a][0] = min(dp[i][j+1][a][0], dp[i][j][a][0] + arr[i][j]);
                if(a > 0) dp[i][j+1][a][0] = min(dp[i][j+1][a][0], dp[i][j][a-1][1] + arr[i][j] + int(pow(2, a - 1)));
            }
    int ans = INT32_MAX;
    for(int i=0;i<20;i++) ans = min({ans, dp[n-1][n-1][i][0], dp[n-1][n-1][i][1]});
    cout<<ans+arr[n-1][n-1]<<endl;
    return 0;
}
