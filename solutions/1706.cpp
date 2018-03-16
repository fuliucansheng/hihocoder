#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 105;
pii arr[maxn];
int dp[maxn][maxn][3000], m, n;
pii calc(int x){
    int a = 0, b = 0;
    while(x % 2 == 0) a++, x /= 2;
    while(x % 5 == 0) b++, x /= 5;
    return pii(a, b);
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr[i] = calc(x);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++) for(int k=0;k<3000;k++) if(dp[i][j][k] != -1){
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                if(k + arr[i].first < 3000) dp[i+1][j+1][k+arr[i].first] = max(dp[i+1][j+1][k+arr[i].first], dp[i][j][k]+arr[i].second);
            }
    }
    int ans = 0;
    for(int a=0;a<3000;a++) ans = max(ans, min(a, dp[n][m][a]));
    cout<<ans<<endl;
    return 0;
}
