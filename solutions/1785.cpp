#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1000010, mod = 1000000007;
ll dp[maxn], n;
ll dfs(ll x) {
    if(dp[x]) return dp[x];
    ll ret = 1;
    for(ll i = 2; i * i <= x; i++) if(x % i == 0) {
        ret += dfs(i), ret %= mod;
        if(i * i != x) ret += dfs(x / i), ret %= mod;
    }
    dp[x] = ret;
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    cin>>n;
    cout<<(dfs(n) + mod) % mod<<endl;
    return 0;
}
