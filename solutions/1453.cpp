#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 10005;
int fa, deg[maxn], dp[maxn], n;
int main() {
    //freopen("../input.txt", "r", stdin);
    memset(deg, 0, sizeof(deg)); memset(dp, inf, sizeof(dp));
    cin>>n;
    for(int i=1;i<n;i++) cin>>fa, deg[fa]++;
    dp[1] = 0;
    for(int i=1;i<=n;i++) if(deg[i]) for(int j=n;j>=1;j--) dp[j + deg[i]] = min(dp[j + deg[i]], dp[j] + 1);
    for(int i=1;i<=n;i++) cout<<(dp[i]<=n ? dp[i] : -1)<<" "; cout<<endl;
    return 0;
}
