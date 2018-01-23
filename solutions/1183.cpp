#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int maxn = 20010;
vector<int> graph[maxn];
int pre[maxn], low[maxn], dfs_clock = 0, m, n;
set<int> rp;
set<pair<int,int>> re;
int dfs(int u, int fa){
    int lowu = pre[u] = ++dfs_clock;
    int ch = 0;
    for(auto v:graph[u])
        if(!pre[v]){
            ch++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if(lowv >= pre[u]) rp.insert(u);
            if(lowv > pre[u]) re.insert(make_pair(min(u,v),max(u,v)));
        }else if(pre[v] < pre[u] && v != fa) lowu = min(lowu, pre[v]);
    if(fa < 0 && ch == 1) rp.erase(u);
    low[u] = lowu;
    return lowu;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(pre, 0, sizeof(pre));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    dfs(1,-1);
    if(rp.size() == 0) cout<<"Null"<<endl;
    else {
        for(auto v:rp) cout<<v<<" ";
        cout<<endl;
    }
    for(auto e:re) cout<<e.first<<" "<<e.second<<endl;
    return 0;
}
