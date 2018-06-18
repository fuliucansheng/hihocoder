#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int ax[maxn], ay[maxn], nx, ny;
int dp[maxn][maxn][2][2], mx[maxn][2], my[maxn][2];
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>nx;
    for(int i = 0; i < nx; i++) cin>>ax[i];
    cin>>ny;
    for(int i = 0; i < ny; i++) cin>>ay[i];
    memset(dp, 0, sizeof(dp)); memset(mx, 0, sizeof(mx)); memset(my, 0, sizeof(my));
    int ans = 0;
    for(int i = 0; i < nx; i++) for(int j = 0; j < ny; j++) {
        if(ax[i] > ay[j]) dp[i][j][1][0] = my[j][0];
        if(ax[i] < ay[j]) dp[i][j][0][0] = my[j][1];
        if(ax[i] == ay[j]) {
            dp[i][j][0][1] = 1 + mx[i][0];
            dp[i][j][1][1] = 1 + mx[i][1];
        }
        mx[i][0] = max(mx[i][0], dp[i][j][0][0]), mx[i][1] = max(mx[i][1], dp[i][j][1][0]);
        my[j][0] = max(my[j][0], dp[i][j][0][1]), my[j][1] = max(my[j][1], dp[i][j][1][1]);
        ans = max({ans, dp[i][j][0][1], dp[i][j][1][1]});
    }
    cout<<ans<<endl;
    return 0;
}
