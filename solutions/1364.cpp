#include <bits/stdc++.h>
using namespace std;
int cnt[15][15], dp[100010], n, m;
int main() {
    //freopen("../input.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt)); memset(dp, 0, sizeof(dp));
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        int w, p; cin>>w>>p;
        cnt[w][p]++;
    }
    for (int i = 1; i <= 10; i++) for (int j = 1; j <= 10; j++) {
            if (!cnt[i][j]) continue;
            int cc = cnt[i][j];
            if (i * cc >= m) for (int mm = i; mm <= m; mm++) dp[mm] = max(dp[mm], dp[mm - i] + j);
            else {
                for (int x = 1; x <= cc; x <<= 1) {
                    for (int mm = m; mm >= (x * i); mm--) dp[mm] = max(dp[mm], dp[mm - x * i] + x * j);
                    cc -= x;
                }
                if (cc) for (int mm = m; mm >= (cc * i); mm--) dp[mm] = max(dp[mm], dp[mm - cc * i] + cc * j);
            }
        }
    cout<<dp[m]<<endl;
    return 0;
}
