#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 100010;
vector<int> graph[maxn];
pii dfs(int u, int f) {
    pii ret = { 0, u };
    for(auto v : graph[u]) if(v != f) {
        auto r = dfs(v, u);
        if(r.first + 1 > ret.first ) ret.first = r.first + 1, ret.second = r.second;
    }
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i = 1; i < n; i++) {
        int u, v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    auto x = dfs(1, 0);
    auto ds = dfs(x.second, 0);
    double ans = log2(ds.first);
    if(double(ans - int(ans)) < 1e-6) cout<<int(ans)<<endl;
    else cout<<int(ans) + 1<<endl;
    return 0;
}
