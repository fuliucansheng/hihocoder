#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
vector<int> graph[maxn];
int arr[maxn], fa[maxn], ht[maxn], n, m;
void dfs(int u, int f, int h){
    fa[u] = f, ht[u] = h;
    for(auto v:graph[u]) if(v != f) dfs(v, u, h + 1);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        for(int i=0;i<maxn;i++) graph[i].clear();
        cin>>n;
        for(int i=1;i<n;i++){
            int u, v; cin>>u>>v;
            graph[u].push_back(v), graph[v].push_back(u);
        }
        dfs(1, 0, 0);
        int mxh = 0;
        cin>>m;
        for(int i=0;i<m;i++) cin>>arr[i], mxh = max(mxh, ht[arr[i]]); mxh++;
        bool status = true;
        while(mxh--){
            set<int> rc;
            for(int i=0;i<m;i++) {
                if(ht[arr[i]] == mxh) arr[i] = fa[arr[i]];
                if(arr[i] != arr[i-1]) rc.insert(arr[i-1]), status = status & (rc.count(arr[i]) == 0);
            }
            if(!status) break;
        }
        cout<<(status ? "YES" : "NO")<<endl;
    }
    return 0;
}