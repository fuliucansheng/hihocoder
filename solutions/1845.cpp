#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1010;
vector<pii> graph[maxn];
vector<int> pp[maxn];
int ds[maxn][maxn];
bool vs[maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, m, q; scanf("%d%d%d", &n, &m, &q);
    for(int i = 0, u, v, z; i < m; i++) {
        scanf("%d%d%d", &u, &v, &z);
        graph[u].push_back(pii(v, z)), graph[v].push_back(pii(u, z));
    }
    memset(ds, inf, sizeof(ds));
    queue<pii> Q;
    Q.push(pii(1,0)), ds[1][0] = 0, vs[1][0] = true;
    while(!Q.empty()) {
        auto f = Q.front(); Q.pop(), vs[f.first][f.second] = false;
        for(auto p : graph[f.first]) {
            if(f.second + 1 <= n && ds[p.first][f.second + 1] > ds[f.first][f.second] + p.second) {
                ds[p.first][f.second + 1] = ds[f.first][f.second] + p.second;
                if(!vs[p.first][f.second + 1]) Q.push(pii(p.first, f.second + 1)), vs[p.first][f.second + 1] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 0; j <= n; j++) if(ds[i][j] < inf) {
                if(pp[i].empty() || ds[i][j] < ds[i][pp[i].back()]) pp[i].push_back(j);
            }
    for(int i = 0; i < q; i++) {
        int c, d; scanf("%d%d", &c, &d);
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for(auto j : pp[c]) ans = min(ans, ds[c][j] + j * ll(d));
        printf("%lld\n", ans);
    }
    return 0;
}
