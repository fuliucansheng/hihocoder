#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int,int> pii;
const ll maxn = 200010;
ll dp[maxn][3], gp[maxn];
vector<pii> graph[maxn];
void dfs(int u, int fa) {
    if(gp[u] == 1) dp[u][2] = inf;
    if(gp[u] == 2) dp[u][1] = inf;
    for(auto p : graph[u]) if(p.first != fa) {
        dfs(p.first, u);
        if(gp[u] != 1) dp[u][2] += min(dp[p.first][2], dp[p.first][1] + p.second);
        if(gp[u] != 2) dp[u][1] += min(dp[p.first][1], dp[p.first][2] + p.second);
    }
}
int main() {
    //freopen("../input.txt", "r", stdin);
    int n, mx, my; cin>>n>>mx;
    vector<int> stx, sty;
    for(int i = 0, a; i < mx; i++) cin>>a, stx.push_back(a), gp[a] = 1;
    cin>>my;
    for(int i = 0, a; i < my; i++) cin>>a, sty.push_back(a), gp[a] = 2;
    for(int i = 1; i < n; i++) {
        int u, v, w; cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dfs(1, 0);
    cout<<min(dp[1][1], dp[1][2])<<endl;
    return 0;
}
