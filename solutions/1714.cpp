#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pdd;
const int maxn = 100010;
int arr[maxn], fa[maxn], n;
vector<int> graph[maxn];
pdd dfs(int u){
    pdd ret = pdd(arr[u], 0);
    for(auto v:graph[u]){
        pdd rv = dfs(v);
        ret.first = ret.first + max(rv.second, rv.first - double(arr[v]) / 2);
        ret.second = ret.second + max(rv.second, rv.first);
    }
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(fa, 0, sizeof(fa));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), fa[v] = u;
    }
    for(int i=1;i<=n;i++) if(fa[i] == 0) {
            pdd ans = dfs(i);
            cout<<fixed<<setprecision(1)<<max(ans.first, ans.second)<<endl;
        }
    return 0;
}
