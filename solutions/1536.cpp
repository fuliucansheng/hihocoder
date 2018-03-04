#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 5050;
pii arr[maxn];
int dp[maxn][maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int t, n, r; cin>>t;
    while(t--){
        cin>>n>>r;
        for(int i=1;i<=n;i++) cin>>arr[i].first;
        for(int i=1;i<=n;i++) cin>>arr[i].second;
        sort(arr+1, arr+n+1); memset(dp, 0, sizeof(dp));
        dp[1][1] = arr[1].second;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++) dp[i][j] = max(dp[i][j], dp[i-1][j] + arr[i].second - arr[i-1].second);
            for(int j=0;j<=i;j++){
                int k = max(i - j - r - 1, 0);
                int s = min(i, k + r + 1);
                dp[i][s] = max(dp[i][s], dp[i-1][k] + arr[i].second);
            }
            for(int j=1;j<=i;j++) dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
        cout<<dp[n][n]<<endl;
    }
    return 0;
}
