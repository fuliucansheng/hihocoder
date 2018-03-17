#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 100010;
vector<pii> graph[maxn];
int dis[maxn], n, m, s, t;
bool vis[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int u, v, d; cin>>u>>v>>d;
        graph[u].push_back(pii(v, d)), graph[v].push_back(pii(u, d));
    }
    memset(vis, 0, sizeof(vis)), memset(dis, 0x3f, sizeof(dis));
    queue<int> Q;
    Q.push(s), dis[s] = 0, vis[s] = true;
    while(!Q.empty()){
        int f = Q.front(); Q.pop(), vis[f] = false;
        for(auto p:graph[f]) if(dis[p.first] > dis[f] + p.second){
                dis[p.first] = dis[f] + p.second;
                if(!vis[p.first]) Q.push(p.first), vis[p.first] = true;
            }
    }
    cout<<dis[t]<<endl;
    return 0;
}