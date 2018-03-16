#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
vector<int> graph[maxn];
int arr[maxn], dp[maxn][maxn], n, m;
void dfs(int u, int f){
    dp[u][1] = arr[u];
    for(auto v:graph[u]) if(v != f){
            dfs(v, u);
            for(int i=m;i>0;i--) for(int j=1;j<i;j++) dp[u][i] = max(dp[u][i], dp[v][j] + dp[u][i-j]);
        }
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    memset(dp, 0, sizeof(dp));
    dfs(1, 0);
    cout<<dp[1][m]<<endl;
    return 0;
}