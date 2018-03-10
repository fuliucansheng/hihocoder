#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
double dp[maxn][maxn], rc[maxn][maxn], a[maxn], s[maxn], s2[maxn];
int rp[maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    memset(s, 0, sizeof(s)); memset(s2, 0, sizeof(s2)); memset(a, 0, sizeof(a)); memset(rp, 0, sizeof(rp));
    for(int i=0;i<maxn;i++) for(int j=0;j<maxn;j++) dp[i][j] = rc[i][j] = 100000000000000000;
    int n, k; cin>>n>>k;
    if(k >= n) return cout<<fixed<<setprecision(3)<<double(0)<<endl, 0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a + 1, a + n + 1);
    for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i], s2[i] = s2[i-1] + a[i] * a[i], rc[i][i] = 0;
    for(int i=1;i<=n;i++) for(int j=2;j<=n;j++) {
            double m = (s[j] - s[i-1]) / double(j - i + 1);
            rc[i][j] = s2[j] - s2[i-1] - 2 * m * (s[j] - s[i-1]) + double(j - i + 1) * m * m;
        }
    for(int i=1;i<=n;i++) dp[i][1] = rc[1][i], rp[n+1][i] = n;
    for(int j=2;j<=k;j++) for(int i=n;i>=1;i--) for(int m=rp[i][j-1];m<=rp[i+1][j];m++) if(dp[i][j] > dp[m][j-1] + rc[m+1][i]) rp[i][j] = m, dp[i][j] = dp[m][j-1] + rc[m+1][i];
    cout<<fixed<<setprecision(3)<<dp[n][k]<<endl;
    return 0;
}
