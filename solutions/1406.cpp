#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 205;
ll dp[maxn][maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i=1;i<=n;i++) dp[i][i] = 0;
    for(int l=1;l<n;l++)
        for(int i=1;i+l<=n;i++){
            dp[i][i+l] = INT32_MAX;
            for(int k=i;k<=i+l;k++) dp[i][i+l] = min(dp[i][i+l], max(dp[i][max(k-1,i)], dp[min(i+l, k+1)][i+l]) + k);
        }
    cout<<dp[1][n]<<endl;
    return 0;
}
