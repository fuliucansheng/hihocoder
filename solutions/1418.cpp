#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 101, maxs = 200020, mod = 1000000007;
ll arr[maxn], dp[maxn][maxs], n, s;
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>arr[i];
    dp[0][maxs/2+arr[0]] = 1, dp[0][maxs/2-arr[0]] = 1;
    for(int i=1;i<n;i++)
        for(int j=0;j<maxs;j++) {
            dp[i][j] = (j+arr[i] < maxs ? dp[i-1][j+arr[i]] : 0) + (j-arr[i] >=0 ? dp[i-1][j-arr[i]] : 0);
            if(dp[i][j] >= mod) dp[i][j] %= mod;
        }
    cout<<dp[n-1][maxs/2+s]<<endl;
    return 0;
}
