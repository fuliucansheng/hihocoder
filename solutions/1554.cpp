#include <bits/stdc++.h>
using namespace std;
int dp[3010][110][110];
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    string a, b, s; cin>>a>>b>>s;
    memset(dp, -1, sizeof(dp));
    int az = int(a.size()), bz = int(b.size()), sz = int(s.size()), ans = INT32_MAX;
    for(int i=0;i<sz;i++) {
        dp[i][0][0] = i;
        for(int j=0;j<=az;j++) for(int k=0;k<=bz;k++)
                if(dp[i][j][k] != -1){
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                    if(j < az && s[i] == a[j]) dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]);
                    if(k < bz && s[i] == b[k]) dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]);
                }
        if(dp[i+1][az][bz] != -1) ans = min(ans, i - dp[i + 1][az][bz] + 1);
    }
    cout<<(ans == INT32_MAX ? -1 : ans)<<endl;
    return 0;
}
