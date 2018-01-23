#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int,int> ps;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        int m, n; cin>>n>>m;
        ps arr[n];
        for(int i=0;i<n;i++){
            int v, s, ss, st = 0; cin>>v>>s;
            for(int j=0;j<s;j++) cin>>ss, st |= (1<<(ss-1));
            arr[i].first = v, arr[i].second = st;
        }
        int maxs = 1<<m;
        int dp[n][maxs]; memset(dp, -1, sizeof(dp));
        dp[0][arr[0].second] = arr[0].first; dp[0][0] = 0;
        for(int i=1;i<n;i++)
            for(int j=0;j<maxs;j++)
                if(dp[i-1][j^arr[i].second] != -1) dp[i][j] = max(dp[i-1][j], arr[i].first + dp[i-1][j^arr[i].second]);
                else dp[i][j] = dp[i-1][j];
        cout<<dp[n-1][maxs-1]<<endl;
    }
    return 0;
}
