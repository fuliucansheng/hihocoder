#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 100010;
int dp[maxn][3][2][3], arr[maxn][5];
int main(){
    //freopen("../input.txt","r",stdin);
    int t, n; cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) for(int j=0;j<5;j++) cin>>arr[i][j];
        memset(dp, inf, sizeof(dp)); dp[0][0][0][0] = 0;
        for(int i=0;i<n;i++) for(int j1=0;j1<3;j1++) for(int j2=0;j2<2;j2++) for(int k=0;k<3;k++){
                        if(dp[i][j1][j2][k] != inf){
                            if(k != 2){
                                dp[i+1][j2+1][1][0] = min(dp[i+1][j2+1][1][0], dp[i][j1][j2][k] + arr[i][j1]);
                                dp[i+1][j2+1][0][2] = min(dp[i+1][j2+1][0][2], dp[i][j1][j2][k] + arr[i][j1+1]);
                            }
                            if(k != 1){
                                dp[i+1][j2][1][1] = min(dp[i+1][j2][1][1], dp[i][j1][j2][k] + arr[i][j1+1]);
                                dp[i+1][j2][0][0] = min(dp[i+1][j2][0][0], dp[i][j1][j2][k] + arr[i][j1+2]);
                            }
                        }
                    }
        int ans = inf;
        for(int k=0;k<3;k++) ans = min(ans, dp[n][2][1][k]);
        cout<<ans<<endl;
    }
    return 0;
}
