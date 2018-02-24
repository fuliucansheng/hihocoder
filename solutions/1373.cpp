#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int arr[12], lc[12], rc[12], deg[12], id[12], rid[12], n, rt;
set<pii> ans;
void dfs(int u, int p){
    ans.insert(pii(p, id[u]));
    if(lc[u] != -1) dfs(lc[u], p - 1);
    if(rc[u] != -1) dfs(rc[u], p + 1);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    while(cin>>n){
        ans.clear();
        if(n == -1) return 0;
        for(int i=0;i<n;i++) {
            cin>>arr[i]>>lc[i]>>rc[i];
            if(lc[i] != -1) deg[lc[i]]++;
            if(rc[i] != -1) deg[rc[i]]++;
        }
        for(int i=0;i<n;i++) if(deg[i] == 0) rt = i;
        queue<int> Q; Q.push(rt);
        int bfs_clock = 0;
        while(!Q.empty()){
            int f = Q.front(); Q.pop();
            rid[bfs_clock] = f; id[f] = bfs_clock++;
            if(lc[f] != -1) Q.push(lc[f]);
            if(rc[f] != -1) Q.push(rc[f]);
        }
        dfs(rt, 1000);
        for(auto pp:ans) cout<<arr[rid[pp.second]]<<" "; cout<<endl;
    }
    return 0;
}
