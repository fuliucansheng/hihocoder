#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010, maxm = 100010;
map<pair<int,int>,int> dict;
vector<int> graph[maxn];
int m, n, t, k, u, v, w[maxm];
bool is_valid(int s){
    bool vis[maxn]; memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(1), vis[1] = true;
    int kk = k;
    while(!Q.empty()){
        int qz = Q.size();
        for(int i = 0; i < qz; i++){
            int f = Q.front(); Q.pop();
            if(f == t) return true;
            for(auto v : graph[f])
                if(!vis[v] && w[dict[make_pair(max(f, v), min(f, v))]] <= s)
                    Q.push(v), vis[v] = true;
        }
        if(--kk < 0) break;
    }
    return false;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(w, 0, sizeof(w));
    cin>>n>>m>>k>>t;
    for(int i = 1; i <= m; i++){
        cin>>u>>v>>w[i];
        graph[u].push_back(v), graph[v].push_back(u);
        pair<int,int> p = make_pair(max(u, v), min(u, v));
        if(!dict[p] || w[i] < w[dict[p]]) dict[p] = i;
    }
    int l = 0, r = 1000000;
    while(r - l > 1){
        int mm = (l + r) / 2;
        if(is_valid(mm)) r = mm; else l = mm;
    }
    cout<<(is_valid(l) ? l : r)<<endl;
    return 0;
}
