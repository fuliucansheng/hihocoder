#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
vector<int> graph[maxn];
map<pair<int,int>,int> dict;
int dis[maxn],vis[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<maxn;i++) dis[i] = INT32_MAX;
    int n,m,s,t,u,v,l;
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++) {
        cin>>u>>v>>l;
        graph[u].push_back(v),graph[v].push_back(u);
        pair<int,int> key = make_pair(min(u,v),max(u,v));
        int value = dict[key];
        dict[key] = value ? min(l,value) : l;
    }
    queue<int> Q;
    dis[s] = 0, vis[s] = 1;
    Q.push(s);
    while(!Q.empty()){
        int f = Q.front();
        vis[f] = 1;
        for(auto e:graph[f]){
            int de = dict[make_pair(min(f,e),max(f,e))];
            if(dis[e] > de + dis[f]) {
                dis[e] = de + dis[f];
                if(vis[e] != 1) Q.push(e), vis[e] = 1;
            }
        }
        vis[f] = 0;
        Q.pop();
    }
    cout<<dis[t]<<endl;
    return 0;
}
