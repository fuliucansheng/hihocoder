#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
const int maxn = 1010;
double arr[maxn], dp[maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    int n, m; cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    dp[0][0] = 1 - arr[0], dp[0][1] = arr[0];
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0]*(1-arr[i]);
        for(int j=1;j<=n;j++) dp[i][j] = (1-arr[i])*dp[i-1][j] + arr[i]*dp[i-1][j-1];
    }
    cout<<fixed<<setprecision(6)<<dp[n-1][m]<<endl;
    return 0;
}
