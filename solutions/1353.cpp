#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 25, maxx = 2010;
int arr[maxn];
bool dp[maxn][maxx];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    int n, x; cin>>n>>x;
    for(int i=0;i<n;i++) cin>>arr[i];
    dp[0][arr[0]] = true, dp[0][0] = true;
    for(int i=1;i<n;i++) for(int j=0;j<maxx;j++) dp[i][j] = ((j >= arr[i] ? dp[i-1][j-arr[i]] : false) | dp[i-1][j]);
    int rs = INT32_MAX;
    for(int i=maxx-1;i>=x;i--) if(dp[n-1][i]) rs = i;
    cout<<(rs == INT32_MAX ? -1 : rs)<<endl;
    return 0;
}

