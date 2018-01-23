#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
typedef pair<char,int> cc;
typedef pair<cc,cc> pp;
const int maxn = 105<<1;
vector<int> graph[maxn];
stack<int> S;
int pre[maxn], low[maxn], scc[maxn], scc_cnt = 0, dfs_clock = 0;
int gid(cc c){
    if(c.first == 'm') return 2*c.second;
    else return 2*c.second+1;
}
int grid(cc c){
    if(c.first == 'h') return 2*c.second;
    else return 2*c.second+1;
}
void dfs(int u){
    pre[u] = low[u] = ++dfs_clock;
    S.push(u);
    for(auto v:graph[u]){
        if(!pre[v]) dfs(v), low[u] = min(low[u], low[v]);
        else if(!scc[v]) low[u] = min(low[u], pre[v]);
    }
    if(low[u] == pre[u]){
        scc_cnt++;
        while(S.top() != u) scc[S.top()] = scc_cnt, S.pop();
        scc[u] = scc_cnt, S.pop();
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    int m,n,k;
    pp p;
    cin>>k;
    while(k--){
        cin>>n>>m;
        memset(pre, 0, sizeof(pre));memset(low, 0, sizeof(low));memset(scc, 0, sizeof(scc));
        dfs_clock = 0,scc_cnt = 0;
        while(!S.empty()) S.pop();
        for(int i=0;i<maxn;i++) graph[i].clear();
        for(int i=0;i<m;i++){
            cin>>p.first.first>>p.first.second>>p.second.first>>p.second.second;
            int c = gid(p.first), rc = grid(p.first), s = gid(p.second), rs = grid(p.second);
            graph[rc].push_back(s),graph[rs].push_back(c);
        }
        for(int i=1;i<=2*n+1;i++) if(!pre[i]) dfs(i);
        bool status = true;
        for(int i=1;i<=n;i++) if(scc[2*i] == scc[2*i+1]) status = false;
        if(status) cout<<"GOOD"<<endl; else cout<<"BAD"<<endl;
    }
    return 0;
}
