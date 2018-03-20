//http://blog.csdn.net/acmmaxx/article/details/38023667
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 1000010;
struct node{
    ll u, v, c0, c1;
}arr[maxn];
bool vs[maxn], rc[maxn];
vector<pll> graph[maxn];
ll dp[maxn][5], n, m;
bool dfs(int u, int f){
    bool ret = vs[u];
    for(auto p:graph[u]) if(f != p.first && dfs(p.first, u)) ret = true;
    //1 -- 人去 人回 //2 -- 人车去 人车回 //0 -- 人去 不回 //3 -- 人车去 人回车不回 //4 -- 人车去 人车不回
    ll r0 = 0, r3 = 0, r4 = 0, t1 = 0x3f3f3f3f3f3f3f3f, t2 = 0x3f3f3f3f3f3f3f3f, mm = -1;
    dp[u][1] = dp[u][2] = dp[u][4] = 0;
    for(auto p:graph[u]) if(f != p.first && rc[p.first]) {
            dp[u][1] += 2 * arr[p.second].c0 + dp[p.first][1];
            ll v2 = min(2 * arr[p.second].c0 + dp[p.first][1], 2 * arr[p.second].c1 + dp[p.first][2]);
            dp[u][2] += v2;
            r0 = min(r0, dp[p.first][0] - dp[p.first][1] - arr[p.second].c0);
            r3 = min(r3, arr[p.second].c0 + arr[p.second].c1 + dp[p.first][3] - v2);
            r4 = min(r4, min(arr[p.second].c0 + dp[p.first][0], arr[p.second].c1 + dp[p.first][4]) - v2);
            ll r = arr[p.second].c0 + arr[p.second].c1 + dp[p.first][3] - v2;
            if(r < t1) mm = p.first, t2 = t1, t1 = r; else t2 = min(t2, r);
        }
    dp[u][0] = dp[u][1] + r0, dp[u][3] = dp[u][2] + r3, dp[u][4] = dp[u][2] + r4, dp[u][4] = min(dp[u][4], dp[u][3]);
    for(auto p:graph[u]) if(f != p.first && rc[p.first]){
            ll v2 = min(2 * arr[p.second].c0 + dp[p.first][1], 2 * arr[p.second].c1 + dp[p.first][2]);
            ll r = arr[p.second].c0 + dp[p.first][0] - v2;
            if(p.first == mm) dp[u][4] = min(dp[u][4], dp[u][2] + t2 + r);
            else dp[u][4] = min(dp[u][4], dp[u][2] + t1 + r);
        }
    rc[u] = ret;
    return ret;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(vs, 0, sizeof(vs)); memset(dp, 0, sizeof(dp));
    cin>>n;
    for(int i=1;i<n;i++) {
        scanf("%lld%lld%lld%lld", &arr[i].u, &arr[i].v, &arr[i].c0, &arr[i].c1);
        graph[arr[i].u].push_back(pll(arr[i].v, i)), graph[arr[i].v].push_back(pll(arr[i].u, i));
    }
    cin>>m;
    for(int i=0, u;i<m;i++) cin>>u, vs[u] = true;
    dfs(1, 0);
    cout<<min(dp[1][0], dp[1][4])<<endl;
    return 0;
}
