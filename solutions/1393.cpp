#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 505;
int mm[maxn], nn[maxn];
struct edge{
    int from, to, cap, flow;
    edge(int f, int t, int c, int w):from(f), to(t), cap(c), flow(w){}
};
struct dinic{
    int d[maxn], cur[maxn], m, n, s, t;
    vector<edge> edges;
    vector<int> graph[maxn];
    bool vis[maxn];
    void init(){
        for(int i=0;i<maxn;i++) graph[i].clear();
        edges.clear();
    }
    void addedge(int f, int t, int c, int w){
        edges.push_back(edge(f, t, c, w));
        edges.push_back(edge(t, f, 0, 0));
        m = int(edges.size());
        graph[f].push_back(m-2), graph[t].push_back(m-1);
    }
    bool bfs(){
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s), d[s] = 0, vis[s] = true;
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for(int i=0;i<graph[x].size();i++){
                edge& e = edges[graph[x][i]];
                if(!vis[e.to] && e.cap > e.flow) vis[e.to] = true, d[e.to] = d[x] + 1, Q.push(e.to);
            }
        }
        return vis[t];
    }
    int dfs(int x, int a){
        if(x == t || a == 0) return a;
        int flow = 0, f;
        for(int& i=cur[x];i<graph[x].size();i++){
            edge& e = edges[graph[x][i]];
            if(d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0){
                e.flow += f, edges[graph[x][i]^1].flow -= f, flow += f, a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }
    int get_maxflow(int s, int t){
        this->s = s, this->t = t;
        int flow = 0;
        while(bfs()){
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, inf);
        }
        return flow;
    }
} dc;
int main() {
    //freopen("../input.txt", "r", stdin);
    int _; cin>>_;
    while(_--){
        dc.init();
        int m, n; cin>>n>>m;
        int s = 0, t = n + m + 1, r = 0;
        for(int i=1;i<=m;i++) cin>>mm[i], dc.addedge(i+n, t, mm[i], 0), r += mm[i];
        for(int i=1;i<=n;i++){
            int a, b, c; cin>>a>>b; dc.addedge(s, i, a, 0);
            for(int j=0;j<b;j++) cin>>c, dc.addedge(i, n+c, 1, 0);
        }
        int mx = dc.get_maxflow(s, t);
        cout<<(mx == r ? "Yes" : "No")<<endl;
    }
    return 0;
}
