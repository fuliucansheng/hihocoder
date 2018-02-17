#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn][maxn], r[maxn][maxn], c[maxn][maxn], dp[maxn][maxn], n;
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
            if(j == 0) r[i][j] = 1, c[j][i] = 1;
            else {
                r[i][j] = ((arr[i][j] - arr[i][j-1]) == 1 ? r[i][j-1] + 1 : 1);
                c[j][i] = ((arr[j][i] - arr[j-1][i]) == 1 ? c[j-1][i] + 1 : 1);
            }
        }
    int ans = 1;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            if(i == 0 || j == 0) dp[i][j] = 1;
            else dp[i][j] = min({r[i][j], c[i][j], dp[i-1][j-1] + 1});
            ans = max(ans, dp[i][j]);
        }
    cout<<ans<<endl;
}
