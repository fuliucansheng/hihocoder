#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int w[maxn], fa[maxn], ans[maxn], n, k;
vector<int> graph[maxn];
void dfs(int u, int f){
    int ff = u;
    ans[u] = f;
    if(w[u] < k) ff = f, ans[u] = -1;
    for(auto v:graph[u]) dfs(v, ff);
}
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>fa[i], graph[fa[i]].push_back(i);
    dfs(graph[0][0], 0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
}
