#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
vector<int> graph[maxn];
int fa[maxn][20], cnt[maxn], ht[maxn], n, m;
void dfs(int u, int h) {
    cnt[u] = 1, ht[u] = h;
    for(auto v : graph[u]) dfs(v, h + 1), cnt[u] += cnt[v];
}
int main() {
    //freopen("../input.txt", "r", stdin);
    memset(fa, 0, sizeof(fa));
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        fa[v][0] = u, graph[u].push_back(v);
    }
    dfs(1, 1);
    for(int k = 1; k < 20; k++) for(int i = 1; i <= n; i++) fa[i][k] = fa[fa[i][k - 1]][k - 1];
    for(int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        if(ht[a] < ht[b]) swap(a, b);
        int a1 = cnt[a], a2 = cnt[b], u = a;
        for (int k = 0; k < 20; k++) if ((ht[u] - ht[b] - 1) >> k & 1) u = fa[u][k];
        if(fa[u][0] == b) a2 = n - cnt[u];
        printf("%lld\n", ll(a1) * ll(a2));
    }
    return 0;
}
