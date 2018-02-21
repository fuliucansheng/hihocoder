#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define px(p) p.first*4+p.second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> edge;
int wgt[17], vis[1<<17], is[16][16], curr_clock = 0, use[16][16], m, n;
ll dp[1<<17][17], ans = 1e18;
vector<edge> g[17], ghp;
void calc(int s, ll w){
    if(vis[s]) return;
    vis[s] = 1, curr_clock++;
    for(int i=0;i<n;i++) if(s>>i&1){
        for(int j=0;j<int(g[i].size());j++){
            pii u = g[i][j].first, v = g[i][j].second;
            if(u.first > v.first || (u.first == v.first && u.second > v.second)) swap(u, v);
            if(!is[px(u)][px(v)]) return;
            use[px(u)][px(v)] = curr_clock;
        }
    }
    for(int i=0;i<int(ghp.size());i++) if(use[px(ghp[i].first)][px(ghp[i].second)] != curr_clock) return;
    ans = min(ans, w);
}
void upd(vector<edge>& gg){
    vector<edge> r;
    for(auto e:gg){
        pii u = e.first, v = e.second;
        int dx = v.first - u.first, dy = v.second - u.second;
        int d = __gcd(abs(dx), abs(dy));
        int ddx = dx / d, ddy = dy / d;
        while (u != v) r.push_back(edge(u, pii(u.first + ddx, u.second + ddy))), u.first += ddx, u.second += ddy;
    }
    gg = r;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(vis, 0, sizeof(vis));
    cin>>n;
    pii u, v;
    for(int i=0;i<n;i++){
        int t; cin>>t>>wgt[i];
        cin>>u.first>>u.second; u.first--, u.second--;
        for(int j=1;j<t;j++) cin>>v.first>>v.second, v.first--, v.second--, g[i].push_back(edge(u,v)), u = v;
        if(t == 1) i--, n++;
        else upd(g[i]);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>u.first>>u.second>>v.first>>v.second; u.first--, u.second--, v.first--, v.second--;
        if(u.first > v.first || (u.first == v.first && u.second > v.second)) swap(u, v);
        ghp.push_back(edge(u, v));
    }
    upd(ghp); sort(ghp.begin(), ghp.end()); ghp.erase(unique(ghp.begin(), ghp.end()), ghp.end());
    for(auto e:ghp) is[px(e.first)][px(e.second)] = 1;
    for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) dp[i][j] = 1e18;
    for(int i=0;i<n;i++) dp[1<<i][i] = wgt[i];
    for(int i=1;i<(1<<n);i++) for(int j=0;j<n;j++) if(dp[i][j] < 1e18){
                calc(i, dp[i][j]);
                for(int k=0;k<n;k++) if(!(i>>k&1)){
                        u = g[j].back().second, v = g[k][0].first;
                        if(u == v) dp[i|(1<<k)][k] = dp[i][j] + wgt[k];
                    }
            }
    cout<<ans<<endl;
    return 0;
}
