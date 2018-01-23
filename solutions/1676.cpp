#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxn = 100010;
map<int,int> rc[maxn];
vector<int> graph[maxn];
int arr[maxn], n;
int dfs(int u, int fa){
    int rr = 1, ds = 0;
    for(auto v:graph[u])
        if(v != fa){
            rr = max(rr, dfs(v, u));
            int d = arr[v] - arr[u];
            if(!d && rc[u][d]) ds = (rc[u][d] < 1 + rc[v][d] ? rc[u][d] : max(ds, 1 + rc[v][d]));
            rc[u][d] = max(rc[u][d], 1 + rc[v][d]);
            if(d) rr = max(rr, rc[u][d] + rc[u][-1*d] + 1);
        }
    if(rc[u][0]) rr = max(rr, rc[u][0] + ds + 1);
    return rr;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    int rs = dfs(1, 0);
    cout<<rs<<endl;
    return 0;
}
