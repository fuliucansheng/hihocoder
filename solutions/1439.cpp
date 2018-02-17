#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct node{
    int fa;
    bool rs;
    string val;
} arr[maxn];
vector<int> graph[maxn];
void dfs1(int u){
    for(auto v:graph[u]) dfs1(v);
    if(arr[u].val == "AND"){
        arr[u].rs = true;
        for(auto v:graph[u]) arr[u].rs &= arr[v].rs;
    }else if(arr[u].val == "OR"){
        arr[u].rs = false;
        for(auto v:graph[u]) arr[u].rs |= arr[v].rs;
    }else arr[u].rs = (arr[u].val == "TRUE");
}
int dfs(int u){
    bool s = true;
    for(int i=1;i<int(graph[u].size());i++) if(arr[graph[u][i]].rs != arr[graph[u][0]].rs) s = false;
    if(arr[u].val == "AND" || arr[u].val == "OR"){
        if(!s) return 1;
        int r = INT32_MAX;
        for(auto v:graph[u]){
            int rs = dfs(v);
            if(rs != -1) r = min(r, rs);
        }
        if(r != INT32_MAX) {
            if(graph[u].size() <= 1 || (arr[u].val == "AND" && arr[u].rs) || (arr[u].val == "OR" && !arr[u].rs)) return r;
            return r + 1;
        }
    }
    return -1;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    int n, root; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i].fa>>arr[i].val;
        graph[arr[i].fa].push_back(i);
        if(arr[i].fa == 0) root = i;
    }
    dfs1(root);
    cout<<dfs(root)<<endl;
    return 0;
}
