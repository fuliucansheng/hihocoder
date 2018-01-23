#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 10010, maxs = 1<<21;
struct job{
    int l,s,e,t,c;
} J[20];
short cs[maxn][maxn];
set<int> rl = {1};
vector<int> graph[maxn];
int m, n, q, dp[maxs][20];
bool dps[maxs][20];
void spfa(int s){
    queue<int> Q;
    int ds[n+1];
    for(int i=1;i<=n;i++) ds[i] = INT32_MAX;
    bool vis[n+1];memset(vis, 0, sizeof(vis));
    Q.push(s); vis[s] = true; ds[s] = 0;
    while(!Q.empty()){
        int u = Q.front();Q.pop();
        vis[u] = false;
        for(auto v:graph[u]){
            int uv = cs[u][v];
            if(vis[v]) ds[v] = min(ds[v], ds[u] + uv);
            else if(ds[v] > ds[u] + uv) Q.push(v), vis[v] = true, ds[v] = ds[u] + uv;
        }
    }
    for(auto l:rl) cs[l][s] = cs[s][l] = ds[l];
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(cs, 0, sizeof(cs));memset(dp, 0, sizeof(dp));memset(dps, 0, sizeof(dps));
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        int u, v;
        short w;
        cin>>u>>v>>w;
        if(cs[u][v]) cs[u][v] = cs[v][u] = min(cs[u][v], w);
        else graph[u].push_back(v), graph[v].push_back(u), cs[u][v] = cs[v][u] = w;
    }
    for(int i=0;i<q;i++) cin>>J[i].l>>J[i].s>>J[i].e>>J[i].t>>J[i].c, rl.insert(J[i].l);
    for(auto l:rl) spfa(l);
    int ms = (1<<q);
    int profit = 0;
    queue<pair<int,int>> Q;
    for(int i=0;i<q;i++) {
        int cc = cs[J[i].l][1];
        if(cc <= J[i].e) dp[(1<<i)][i] = J[i].t + max(J[i].s, cc), Q.push(make_pair(1<<i, i)), dps[1<<i][i] = true;
    }
    while(!Q.empty()){
        pair<int,int> pr = Q.front(); Q.pop();
        int s = pr.first, l = pr.second, qz = Q.size();
        dps[s][l] = false;
        for(int k=0;k<q;k++){
            if((s & (1<<k)) != 0 || dp[s][l] + cs[J[l].l][J[k].l] > J[k].e) continue;
            int ns = s | (1<<k), nsk = J[k].t + max(J[k].s, dp[s][l] + cs[J[l].l][J[k].l]);
            if(dps[ns][k]) dp[ns][k] = min(dp[ns][k], nsk);
            else if(dp[ns][k] == 0 || dp[ns][k] > nsk) dp[ns][k] = nsk, dps[ns][k] = true, Q.push(make_pair(ns,k));
        }
        if(Q.size() == qz){
            int cp = 0;
            for(int i=0;i<q;i++) if((s&(1<<i)) != 0) cp += J[i].c;
            profit = max(profit, cp);
        }
    }
    cout<<profit<<endl;
    return 0;
}
