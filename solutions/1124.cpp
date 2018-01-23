#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 101, mod = 1000000007;
ll dp[maxn][maxn][maxn], ans[maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    for(int m=1;m<=100;m++){
        memset(dp, 0, sizeof(dp));
        dp[0][m][0] = 1;
        for(int n=0;n<maxn-1;n++) {
            for(int a=0;a<=m;a++)
                for(int b=0;b<=m-a;b++){
                    dp[n+1][a][b] += dp[n][a][b], dp[n][a][b] %= mod;
                    if(a > 0) dp[n+1][a-1][b+1] += ll(a)*dp[n][a][b], dp[n+1][a-1][b+1] %= mod;
                    if(b > 0) dp[n+1][a][b-1] += ll(b)*dp[n][a][b], dp[n+1][a][b-1] %= mod;
                    if(a > 0) dp[n+1][a-1][b] += ll(a)*dp[n][a][b], dp[n+1][a-1][b] %= mod;
                    if(a > 1) dp[n+1][a-2][b+2] += (ll(a)*ll(a-1)/2)*dp[n][a][b], dp[n+1][a-2][b+2] %= mod;
                    if(a > 0) dp[n+1][a-1][b] += ll(a)*ll(b)*dp[n][a][b], dp[n+1][a-1][b] %= mod;
                    if(b > 1) dp[n+1][a][b-2] += (ll(b)*ll(b-1)/2)*dp[n][a][b], dp[n+1][a][b-2] %= mod;
                }
            ans[n+1][m] = 0;
            for(int a=0;a<=m;a++) for(int b=0;b<=m;b++) ans[n+1][m] += dp[n+1][a][b], ans[n+1][m] %= mod;
        }
    }
    int t; cin>>t;
    while(t--){
        int m, n; cin>>n>>m;
        cout<<(ans[n][m] >= 0 ? ans[n][m] : ans[n][m] + mod)<<endl;
    }
    return 0;
}
