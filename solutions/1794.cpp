#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int a[maxn], dp[1 << 20], n;
int dfs(int s) {
    if(dp[s] != -1) return dp[s];
    vector<int> dg;
    for(int i = 0; i < n; i++) if((s & (1 << i)) == 0) dg.push_back(i);
    int dsz = int(dg.size()), ret = 0;
    for(int i = 0; i < dsz; i++) for(int j = i + 1; j < dsz; j++) for(int k = j + 1; k < dsz; k++) {
        if(a[dg[i]] + a[dg[j]] <= a[dg[k]]) break;
        ret = max(ret, 1 + dfs(s | (1 << dg[i]) | (1 << dg[j]) | (1 << dg[k])));
    }
    dp[s] = ret;
    return ret;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n); memset(dp, -1, sizeof(dp));
    cout<<dfs(0)<<endl;
    return 0;
}
