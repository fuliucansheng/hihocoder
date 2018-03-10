#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long ll;
const int maxn = 100000;
struct edge{
    int from, to, cap, flow, cost;
    edge(int f, int t, int c, int w, int s):from(f), to(t), cap(c), flow(w), cost(s){}
};
struct mcmf{
    int a[maxn], p[maxn], d[maxn], inq[maxn], m, n;
    vector<edge> edges;
    vector<int> graph[maxn];
    void init(){
        for(int i=0;i<maxn;i++) graph[i].clear();
        edges.clear();
    }
    void addedge(int f, int t, int c, int s, int w = 0){
        edges.push_back(edge(f, t, c, w, s));
        edges.push_back(edge(t, f, 0, 0, -1*s));
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
        int flow = 0;
        while(bellmanford(s, t, flow, cost));
        return flow;
    }
} mcf;
int a[210][210], af[210][210], at[210][210], c = 0, n;
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    mcf.init();
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            cin>>a[i][j];
            af[i][j] = c++, at[i][j] = c++;
            if((i == 0 && j == 0) || (i == n-1 && j == n-1)) mcf.addedge(af[i][j], at[i][j], 2, 0);
            else mcf.addedge(af[i][j], at[i][j], 1, 0);
            if(i > 0) mcf.addedge(at[i-1][j], af[i][j], 1, -a[i-1][j]);
            if(j > 0) mcf.addedge(at[i][j-1], af[i][j], 1, -a[i][j-1]);
        }
    int s = af[0][0], t = at[n-1][n-1];
    ll ans = 0;
    if(n > 1) mcf.get_min_cost_max_flow(s, t, ans);
    ans = -ans + a[n-1][n-1] * 2;
    cout<<ans<<endl;
    return 0;
}
