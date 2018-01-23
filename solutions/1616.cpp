#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 10010;
vector<int> graph[maxn];
int lc[maxn], rc[maxn], fa[maxn], rec[maxn], pc = 0;
bool vis[maxn];
void pg(int u){
    cout<<"(";
    if(u) cout<<u;
    if(u) pg(lc[u]),pg(rc[u]);
    cout<<")";
}
void dfs(int u){
    if(lc[u]) dfs(lc[u]);
    rec[pc++] = u;
    if(rc[u]) dfs(rc[u]);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        memset(lc, 0, sizeof(lc)); memset(rc, 0, sizeof(rc)); memset(vis, 0, sizeof(vis));
        memset(fa, 0, sizeof(fa)); memset(rec, 0, sizeof(rec)); pc = 0;
        for(int i=0;i<maxn;i++) graph[i].clear();
        int n, a, b, r; cin>>n;
        for(int i=1;i<n;i++) cin>>a>>b, graph[a].push_back(b), fa[b] = a;
        for(int i=1;i<=n;i++) if(!fa[i]) { r = i; break; }
        queue<int> Q;
        Q.push(r), vis[r] = true;
        while(!Q.empty()){
            int f = Q.front(); Q.pop();
            for(auto v:graph[f]) if(!vis[v]) Q.push(v), vis[v] = true;
        }
        int es = 0;
        for(int i=1;i<=n;i++) if(!vis[i]) { es = 1; break; }
        if(es == 1) { cout<<"ERROR1"<<endl; continue; }
        for(int i=1;i<=n;i++) if(int(graph[i].size()) > 2) { es = 2; break; }
        if(es == 2) { cout<<"ERROR2"<<endl; continue; }
        for(int i=1;i<=n;i++)
            if(fa[i]){
                if(i > fa[i]){
                    if(rc[fa[i]]) { es = 3; break; }
                    else rc[fa[i]] = i;
                }else if(i < fa[i]){
                    if(lc[fa[i]]) { es = 3; break; }
                    else lc[fa[i]] = i;
                }
            }
        if(es != 3) {
            dfs(r);
            for(int i=1;i<n;i++) if(rec[i] < rec[i-1]) { es = 3; break; }
        }
        if(es == 3) { cout<<"ERROR3"<<endl; continue; }
        pg(r);
        cout<<endl;
    }
    return 0;
}
