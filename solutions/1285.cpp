#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 1100;
int arr[maxn], dp[maxn][maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int q; cin>>q;
    while(q--){
        int m, n, s, t; cin>>n>>m>>s>>t;
        for(int i=1;i<=n;i++) cin>>arr[i];
        memset(dp, inf, sizeof(dp)); dp[0][0] = 0;
        for(int i=1;i<=n;i++) for(int j=0;j<=m;j++) {
                int lmt = arr[i]/s + (arr[i]%s != 0);
                for(int k=0;k<=lmt;k++){
                    int r = arr[i] - s * k;
                    int c = k + (r > 0 ? r / t + (r % t != 0) : 0);
                    if(j >= c && dp[i-1][j-c] != inf) dp[i][j] = min(dp[i][j], dp[i-1][j-c] + k);
                }
            }
        int ans = inf;
        for(int i=0;i<=m;i++) ans = min(ans, dp[n][i]);
        if(ans != inf) cout<<ans<<endl; else cout<<"No"<<endl;
    }
    return 0;
}
