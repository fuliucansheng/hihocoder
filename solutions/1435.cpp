#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> graph[maxn];
int deg[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        for(int i=0;i<maxn;i++) graph[i].clear();
        memset(deg, 0, sizeof(deg));
        int n, m; cin>>n>>m;
        for(int i=0;i<m;i++){
            int u, v; cin>>u>>v;
            graph[u].push_back(v), deg[v]++;
        }
        queue<int> Q;
        for(int i=1;i<=n;i++) if(deg[i] == 0) Q.push(i);
        while(!Q.empty()){
            int f = Q.front(); Q.pop();
            for(auto v:graph[f]) {
                deg[v]--;
                if(deg[v] == 0) Q.push(v);
            }
        }
        bool status = false;
        for(int i=1;i<=n;i++) if(deg[i] > 0) { status = true; break; }
        cout<<(status ? "YES" : "NO")<<endl;
    }
    return 0;
}
