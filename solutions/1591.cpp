#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long ll;
const int maxn = 10105;
struct edge{
    int from, to, cap, flow, cost;
    edge(int f, int t, int c, int w, int s):from(f), to(t), cap(c), flow(w), cost(s){}
};
struct mcmf{
    int a[maxn], p[maxn], d[maxn], inq[maxn], m;
    vector<edge> edges;
    vector<int> graph[maxn];
    void init(){
        for(int i=0;i<maxn;i++) graph[i].clear();
        edges.clear();
    }
    void addedge(int f, int t, int c, int w, int s){
        edges.push_back(edge(f, t, c, w, s));
        edges.push_back(edge(t, f, 0, 0, -s));
        m = int(edges.size());
        graph[f].push_back(m-2), graph[t].push_back(m-1);
    }
    bool bellmanford(int s, int t, int &flow, ll& cost){
        memset(d, inf, sizeof(d)); memset(inq, 0, sizeof(inq));
        d[s] = 0, inq[s] = 1, p[s] = 0, a[s] = inf;
        queue<int> Q; Q.push(s);
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for(int i=0;i<graph[u].size();i++){
                edge& e = edges[graph[u][i]];
                if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost, p[e.to] = graph[u][i], a[e.to] = min(a[u], e.cap - e.flow);
                    if(!inq[e.to]) Q.push(e.to), inq[e.to] = 1;
                }
            }
        }
        if(d[t] == inf) return false;
        flow += a[t], cost += ll(d[t])*ll(a[t]);
        for(int u=t;u!=s;u=edges[p[u]].from) edges[p[u]].flow += a[t], edges[p[u]^1].flow -= a[t];
        return true;
    }
    int get_min_cost_max_flow(int s, int t, ll& cost){
        int flow = 0; cost = 0;
        while(bellmanford(s, t, flow, cost));
        return flow;
    }
} mcf;
int rc[105][105], vis[105][105];
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    memset(rc, 0, sizeof(rc)); memset(vis, 0, sizeof(vis));
    int n, k; cin>>n;
    int s = 0, t = n + n * n + 1, nc = n + 1;
    mcf.init();
    for(int i=1;i<=n;i++) {
        int a; cin>>a;
        mcf.addedge(s, i, a, 0, 0);
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) rc[i][j] = nc, mcf.addedge(nc, t, 1, 0, 0), nc++;
    cin>>k;
    for(int i=0;i<k;i++){
        int u, v; cin>>u>>v;
        vis[v][u] = 1;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            int b; cin>>b;
            if(i == j) continue;
            if(!vis[i][j]) mcf.addedge(i, rc[min(i,j)][max(i,j)], 1, 0, -b);
        }
    ll ans = 0;
    mcf.get_min_cost_max_flow(s, t, ans);
    cout<<-ans<<endl;
    return 0;
}
