#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t, m, n, u, v; cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> graph[n+1];
        int deg[n+1], vis[n+1];
        memset(deg, 0, sizeof(deg));memset(vis, 0, sizeof(vis));
        for(int i=0;i<m;i++) cin>>u>>v, graph[u].push_back(v), deg[v]++;
        queue<int> Q;
        for(int i=1;i<=n;i++) if(!deg[i]) Q.push(i), vis[i] = 1;
        while(!Q.empty()){
            int f = Q.front(); Q.pop();
            vis[f] = 1;
            for(auto vv:graph[f]) if(--deg[vv] == 0) Q.push(vv);
        }
        bool status = true;
        for(int i=1;i<=n;i++) if(!vis[i]) status = false;
        if(status) cout<<"Correct"<<endl; else cout<<"Wrong"<<endl;
    }
    return 0;
}
