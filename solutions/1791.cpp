#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[15][2][110][110], cc[15][110];
vector<int> dig;
ll calc(int x) {
    memset(dp, 0, sizeof(dp));
    int sz = int(dig.size());
    dp[0][1][dig[0]][dig[0] % x] = 1;
    for(int i = 1; i < dig[0]; i++) dp[0][0][i][i % x] = 1;
    for(int i = 0; i + 1 < sz; i++) for(int a = 0; a <= x; a++) for(int b = 0; b < x; b++) {
        if(dp[i][0][a][b]) for(int k = 0; k < 10; k++) dp[i + 1][0][a + k][(b * 10 + k) % x] += dp[i][0][a][b];
        if(dp[i][1][a][b]) {
            for(int k = 0; k < dig[i + 1]; k++) dp[i + 1][0][a + k][(b * 10 + k) % x] += dp[i][1][a][b];
            dp[i + 1][1][a + dig[i + 1]][(b * 10 + dig[i + 1]) % x] += dp[i][1][a][b];
        }
    }
    ll ret = dp[sz - 1][0][x][0] + dp[sz - 1][1][x][0];
    return ret;
}
void init(ll x) {
    dig.clear();
    while(x) dig.push_back(int(x % 10)), x /= 10;
    reverse(dig.begin(), dig.end());
}
int main(){
    //freopen("../input.txt", "r", stdin);
    for(int i = 1; i < 13; i++) {
        ll x = ll(pow(10, i)) - 1;
        init(x);
        for(int j = 1; j < 110; j++) cc[i][j] = calc(j);
    }
    for(int i = 1; i < 13; i++) for(int j = 1; j < 110; j++) cc[i][j] += cc[i - 1][j];
    ll n; cin>>n; init(n);
    ll ans = 0;
    for(int i = 1; i < 110; i++) ans += calc(i) + cc[dig.size() - 1][i];
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[15][2][110][110];
vector<int> dig;
int nn;
ll dfs(int x, int a, int b, int k) {
    if(dp[x][k][a][b] != -1) return dp[x][k][a][b];
    if(a < 0) return 0;
    if(x == dig.size()) return b == 0 && a == 0;
    ll ret = 0;
    if(k == 0) for(int i = 0; i < 10; i++) ret += dfs(x + 1, a - i, (b * 10 + i) % nn, 0);
    else {
        for(int i = 0; i < dig[x]; i++) ret += dfs(x + 1, a - i, (b * 10 + i) % nn, 0);
        ret += dfs(x + 1, a - dig[x], (b * 10 + dig[x]) % nn, 1);
    }
    dp[x][k][a][b] = ret;
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n; cin>>n;
    while(n) dig.push_back(int(n % 10)), n /= 10;
    reverse(dig.begin(), dig.end());
    ll ans = 0;
    for(int i = 1; i < 110; i++) {
        memset(dp, -1, sizeof(dp));
        nn = i, ans += dfs(0, i, 0, 1);
    }
    cout<<ans<<endl;
    return 0;
}
