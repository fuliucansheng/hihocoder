#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef pair<int,int> pii;
const int maxn = 105;
vector<pii> graph[maxn];
int dp[maxn][2][maxn<<1], arr[maxn], wgt[maxn], n, q;
void dfs(int u, int f){ // 0--回 1--不回
    dp[u][0][0] = dp[u][1][0] = dp[u][0][arr[u]] = dp[u][1][arr[u]] = 0;
    for(auto p:graph[u]) if(f != p.first){
            dfs(p.first, u);
            for(int i=(maxn<<1)-1;i>=0;i--) for(int j=0;j<i;j++) if(dp[u][0][j] != inf){
                if(dp[p.first][0][i-j] != inf) dp[u][0][i] = min(dp[u][0][i], dp[u][0][j] + dp[p.first][0][i-j] + 2 * wgt[p.second]);
                if(dp[p.first][1][i-j] != inf) dp[u][1][i] = min({dp[u][1][i], dp[u][0][j] + dp[p.first][1][i-j] + wgt[p.second], dp[u][1][j] + dp[p.first][0][i-j] + 2 * wgt[p.second]});
            }
        }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dp, inf, sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v>>wgt[i];
        graph[u].push_back(pii(v, i)), graph[v].push_back(pii(u, i));
    }
    dfs(1, 0);
    cin>>q;
    for(int i=0;i<q;i++){
        int d, ans = 0; cin>>d;
        for(int j=(maxn<<1)-1;j>=0;j--) if(dp[1][1][j] <= d) { ans = j; break; }
        cout<<ans<<endl;
    }
    return 0;
}
