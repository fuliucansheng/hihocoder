#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 1001;
int rc[maxn][maxn], dp[maxn][25], tp1[450], tp2[450];
struct node{
    int a, b, c;
} arr[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int n, k; cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i].a>>arr[i].b>>arr[i].c;
    for(int i=0;i<n;i++) {
        memset(tp1, 0, sizeof(tp1)); memset(tp2, 0, sizeof(tp2));
        for(int j=i;j<n;j++){
            int aa = arr[j].a, bb = arr[j].b - 3, cc = arr[j].c - 7, c1 = INT32_MAX, c2 = INT32_MAX;
            for(int r=0;r<=400;r++) {
                tp1[r] += abs(aa + 200 - r) + abs(bb + 200 - r) + abs(cc + 200 - r);
                tp2[r] += abs(aa + 200 - r) + abs(bb + 200 - 1 - r) + abs(cc + 200 - r);
                c1 = min(c1, tp1[r]), c2 = min(c2, tp2[r]);
            }
            rc[i][j] = min(c1, c2);
        }
    }
    memset(dp, inf, sizeof(dp));
    for(int i=0;i<n;i++) dp[i][0] = rc[0][i];
    for(int i=1;i<=k;i++) for(int j=0;j<n;j++) for(int r=0;r<j;r++) dp[j][i] = min(dp[j][i], dp[r][i-1] + rc[r+1][j]);
    int ans = inf;
    for(int i=0;i<=k;i++) ans = min(dp[n-1][i], ans);
    cout<<ans<<endl;
    return 0;
}
