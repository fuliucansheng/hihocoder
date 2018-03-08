#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int arr[maxn][maxn], dp[maxn][maxn][25], n, q;
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>arr[i][j];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            for(int k=0;k<25;k++) dp[i][j][k] = dp[i][j-1][k];
            dp[i][j][arr[i][j]]++;
        }
    cin>>q;
    for(int _=0;_<q;_++){
        int i, j, k; cin>>i>>j>>k;
        int ans = 0;
        for(int x=1;x<25;x++) if(k % x == 0){
                for(int a=max(0,i-k);a<=min(n,i+k);a++) {
                    int d = k - abs(a - i);
                    int br = min(n,j+d), bl = max(0,j-d-1);
                    ans += dp[a][br][x] - dp[a][bl][x];
                }
            }
        cout<<ans<<endl;
    }
    return 0;
}
