#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][15][3][2], cc[20];
ll cnt(ll x) {
    if(x < 10) return x + 1;
    memset(dp, 0, sizeof(dp));
    vector<ll> num;
    while(x) num.push_back(x % 10), x /= 10;
    reverse(num.begin(), num.end());
    int sz = int(num.size());
    ll ret = 0;
    dp[0][num[0]][0][1] = 1;
    for(int i = 1; i < num[0]; i++) dp[0][i][0][0] = 1;
    //0 -- 不确定递增递减 | 1 -- 递增 | 2 -- 递减 ------- （与x的大小） 0 -- 确定 | 1 -- 不确定
    for(int i = 1; i < sz; i++) {
        for(int j = 0; j < 10; j++) {
            if(j < num[i]) {
                dp[i][j][0][0] += dp[i - 1][j][0][0] + dp[i - 1][j][0][1];
                for(int k = 0; k < j; k++) dp[i][j][1][0] += dp[i - 1][k][1][0] + dp[i - 1][k][1][1] + dp[i - 1][k][0][0] + dp[i - 1][k][0][1];
                dp[i][j][1][0] += dp[i - 1][j][1][0] + dp[i - 1][j][1][1];
                for(int k = j + 1; k < 10; k++) dp[i][j][2][0] += dp[i - 1][k][2][0] + dp[i - 1][k][2][1] + dp[i - 1][k][0][0] + dp[i - 1][k][0][1];
                dp[i][j][2][0] += dp[i - 1][j][2][0] + dp[i - 1][j][2][1];
            } else if(j > num[i]) {
                dp[i][j][0][0] += dp[i - 1][j][0][0];
                for(int k = 0; k < j; k++) dp[i][j][1][0] += dp[i - 1][k][1][0] + dp[i - 1][k][0][0];
                dp[i][j][1][0] += dp[i - 1][j][1][0];
                for(int k = j + 1; k < 10; k++) dp[i][j][2][0] += dp[i - 1][k][2][0] + dp[i - 1][k][0][0];
                dp[i][j][2][0] += dp[i - 1][j][2][0];
            } else {
                dp[i][j][0][0] += dp[i - 1][j][0][0], dp[i][j][0][1] += dp[i - 1][j][0][1];
                for(int k = 0; k < j; k++)  dp[i][j][1][0] += dp[i - 1][k][1][0] + dp[i - 1][k][0][0], dp[i][j][1][1] += dp[i - 1][k][1][1] + dp[i - 1][k][0][1];
                dp[i][j][1][0] += dp[i - 1][j][1][0], dp[i][j][1][1] += dp[i - 1][j][1][1];
                for(int k = j + 1; k < 10; k++)  dp[i][j][2][0] += dp[i - 1][k][2][0] + dp[i - 1][k][0][0], dp[i][j][2][1] += dp[i - 1][k][2][1] + dp[i - 1][k][0][1];
                dp[i][j][2][0] += dp[i - 1][j][2][0], dp[i][j][2][1] += dp[i - 1][j][2][1];
            }
        }
    }
    for(int i = 0; i < 10; i++) for(int j = 0; j < 3; j++) ret += dp[sz - 1][i][j][0] + dp[sz - 1][i][j][1];
    return ret + cc[sz - 1];
}

int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    for(ll i = 1; i <= 18; i++) cc[i] = cnt(ll(pow(10, i)) - 1);
    while(t--) {
        ll l, r; cin>>l>>r;
        cout<<cnt(r) - cnt(l - 1)<<endl;
    }
    return 0;
}
