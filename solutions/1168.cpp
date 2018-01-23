#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 100010;
vector<int> graph[maxn];
ll rec[maxn];
void dfs(int u, int fa){
    for(auto v:graph[u]) if(v != fa) dfs(v, u), rec[u] += rec[v];
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    for(int ts=1;ts<=t;ts++){
        int n, s; cin>>n>>s;
        for(int i=1;i<n;i++){
            int u, v; cin>>u>>v;
            graph[u].push_back(v), graph[v].push_back(u);
        }
        for(int i=1;i<=n;i++) cin>>rec[i];
        dfs(s, 0);
        ll rs = 0;
        for(auto v:graph[s]) rs = max(rs, rec[v]);
        cout<<"Case #"<<ts<<": "<<rs<<endl;
        for(int i=1;i<=n;i++) graph[i].clear();
    }
    return 0;
}
