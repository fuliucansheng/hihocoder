#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010, mod = 142857;
int deg[maxn], cnt[maxn], ss[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int t, m, n, k, s, e; scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(deg, 0, sizeof(deg)); memset(cnt, 0, sizeof(cnt));
        vector<int> graph[maxn];
        queue<int> Q;
        for(int i = 0; i < m; i++) scanf("%d", &s), cnt[s]++;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &ss[i], &k);
            for(int j = 0; j < k; j++) scanf("%d", &e), graph[ss[i]].push_back(e), deg[e]++;
        }
        for(int i = 0; i < maxn; i++) if(!deg[i]) Q.push(i);
        while(!Q.empty()){
            int f = Q.front(); Q.pop();
            for(auto v : graph[f]) {
                deg[v]--, cnt[v] += cnt[f], cnt[v] %= mod;
                if(!deg[v]) Q.push(v);
            }
        }
        for(int i = 0; i < n; i++) cout<<cnt[ss[i]]<<" "; cout<<endl;
    }
    return 0;
}
