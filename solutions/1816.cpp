#include <bits/stdc++.h>
using namespace std;
const int maxn = 2020;
int b[maxn], s[maxn], dp[maxn][maxn], n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n, n *= 2;
    for(int i = 1; i <= n; i++) cin>>b[i]>>s[i];
    dp[1][0] = b[1], dp[1][1] = s[1];
    for(int i = 2; i <= n; i++) for(int j = 0; j <= i; j++) dp[i][j] = max((j ? dp[i - 1][j - 1] : 0) + s[i], dp[i - 1][j] + b[i]);
    cout<<dp[n][n / 2]<<endl;
    return 0;
}
