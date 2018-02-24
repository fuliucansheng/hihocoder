#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int node[maxn];
vector<int> graph[maxn];
bool bfs(int n, int type){
    if(node[n] == -1) node[n] = type;
    if(node[n] != type) return false;
    for(auto g:graph[n]) {
        if(node[g] != -1 && node[g] != 1-type) return false;
        if(node[g] == -1) bfs(g, 1-type);
    }
    return true;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t, m, n, u, v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(node, -1, sizeof(node));
        for(int i=0;i<m;i++) {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool status = true;
        for(int i=1;i<=n;i++) if(status && node[i] == -1) status &= bfs(i, 0);
        cout<<(status ? "Correct" : "Wrong")<<endl;
        for(int i=1;i<=n;i++) graph[i].clear();
    }
    return 0;
}
