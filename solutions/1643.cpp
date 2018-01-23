#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 5e4+50, maxk = 5e6+50;
vector<int> graph[maxn], scc[maxk];
int n;
int spfa(int s, int e){
    int dis[n], vis[n];memset(vis, 0, sizeof(vis));
    for(int i=0;i<n;i++) dis[i] = INT32_MAX;
    queue<int> Q;
    for(auto ss:scc[s]) dis[ss] = 0, Q.push(ss), vis[ss] = 1;
    while(!Q.empty()){
        int f = Q.front();Q.pop();
        vis[f] = 1;
        for(auto v:graph[f]){
            if(dis[v] > dis[f] + 1){
                dis[v] = dis[f] + 1;
                if(!vis[v]) Q.push(v), vis[v] = 1;
            }
        }
        vis[f] = 0;
    }
    int r = INT32_MAX;
    for(auto ee:scc[e]) r = min(r, dis[ee]);
    return r;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int s,e,k,u;
    cin>>n>>s>>e;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++) {
            cin>>u;
            for(auto c: scc[u]) if(c != i) graph[c].push_back(i), graph[i].push_back(c);
            scc[u].push_back(i);
        }
    }
    int r = spfa(s, e);
    cout<<(r == INT32_MAX ? -1 : r)<<endl;
    return 0;
}
