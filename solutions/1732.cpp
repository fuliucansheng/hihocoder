#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
ll dp[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    memset(dp, 0, sizeof(dp));
    dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cout<<dp[n]<<endl;
    return 0;
}
