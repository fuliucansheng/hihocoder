#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<pair<int,int>> graph[maxn];
map<pair<int,int>,int> dict;
long long cnt[maxn], dis[maxn], nnt[maxn], vis[maxn], m, n;
void dfs(int u){
    vis[u] = true;
    for(auto p:graph[u]) if(!vis[p.second]) dfs(p.second);
    for(auto p:graph[u]) nnt[u] += nnt[p.second];
    nnt[u]++;
    for(auto p:graph[u]) cnt[p.first] = (n - nnt[p.second])*nnt[p.second];
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));memset(vis, 0, sizeof(vis));memset(nnt, 0, sizeof(nnt));
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v>>dis[i];
        graph[u].push_back(make_pair(i,v)), graph[v].push_back(make_pair(i,u));
        dict[make_pair(min(u,v), max(u,v))] = i;
    }
    dfs(1);
    long long rs = 0;
    for(int i=1;i<n;i++) rs += cnt[i] * dis[i];
    while(m--){
        string s; cin>>s;
        if(s == "EDIT"){
            int i,j,k; cin>>i>>j>>k;
            int l = dict[make_pair(min(i,j), max(i,j))];
            rs += cnt[l] * (k - dis[l]);
            dis[l] = k;
        }else cout<<rs<<endl;
    }
    return 0;
}
