#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 105;
int score[maxn], dp[maxn][maxn], m, n, k;
vector<int> graph[maxn];
void dfs(int u, int p){
    dp[u][1] = score[u];
    for(auto v:graph[u]){
        if(v != p){
            dfs(v, u);
            for(int i=m;i>=1;i--) for(int j=1;j<=m-i;j++) dp[u][i+j] = max(dp[u][i+j], dp[u][i]+dp[v][j]);
        }
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++) cin>>score[i];
    for(int i=0;i<k;i++){
        int rcm; cin>>rcm;
        score[rcm] += 20000;
    }
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    dfs(1, 0);
    int rs = dp[1][m] - 20000*k;
    cout<<(rs < 0 ? -1 : rs)<<endl;
    return 0;
}
