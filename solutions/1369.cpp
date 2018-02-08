#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 505;
struct edge{
    int from, to, cap, flow;
    edge(int f, int t, int c, int w):from(f), to(t), cap(c), flow(w){}
};
struct edmondskarp{
    int a[maxn], p[maxn], m, n;
    vector<edge> edges;
    vector<int> graph[maxn];
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
    int get_maxflow(int s, int t){
        int flow = 0;
        for(;;){
            memset(a, 0, sizeof(a));
            queue<int> Q;
            Q.push(s), a[s] = inf;
            while(!Q.empty()){
                int x = Q.front(); Q.pop();
                for(int i=0;i<int(graph[x].size());i++){
                    edge& e = edges[graph[x][i]];
                    if(!a[e.to] && e.cap > e.flow) p[e.to] = graph[x][i], a[e.to] = min(a[x], e.cap - e.flow), Q.push(e.to);
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u=t;u!=s;u=edges[p[u]].from) edges[p[u]].flow += a[t], edges[p[u]^1].flow -= a[t];
            flow += a[t];
        }
        return flow;
    }
};
int main() {
    //freopen("../input.txt", "r", stdin);
    int m, n; cin>>n>>m;
    edmondskarp ep; ep.init();
    for(int i=0;i<m;i++){
        int u, v, c; cin>>u>>v>>c;
        ep.addedge(u, v, c, 0);
    }
    cout<<ep.get_maxflow(1, n)<<endl;
    return 0;
}
