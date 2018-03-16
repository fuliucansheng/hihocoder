#include <bits/stdc++.h>
using namespace std;
const int N = 1<<10;
int dp[1001][N];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(dp, 0, sizeof(dp));
    int m,n,q,num;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>num;
        for(int j=0;j<=(1<<m);j++){
            if(__builtin_popcount(j) > q) continue;
            if(j&1) dp[i][j] = max(dp[i-1][j>>1], dp[i-1][(j>>1)+(1<<m-1)]) + num;
            else dp[i][j] = max(dp[i-1][j>>1], dp[i-1][(j>>1)+(1<<m-1)]);
        }
    }
    int ans = 0;
    for(int i=0;i<=(1<<m);i++) ans = max(ans, dp[n][i]);
    cout<<ans<<endl;
    return 0;
}
