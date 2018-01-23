#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e5+10, mod = 142857;
int deg[maxn], rec[maxn], ss[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int t, m, n, k, s, e; scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(deg, 0, sizeof(deg));memset(rec, 0, sizeof(rec));
        vector<int> graph[maxn];
        queue<int> Q;
        for(int i=0;i<m;i++) scanf("%d", &s), rec[s]++;
        for(int i=0;i<n;i++){
            scanf("%d%d", &ss[i], &k);
            for(int j=0;j<k;j++) scanf("%d", &e), graph[ss[i]].push_back(e), deg[e]++;
        }
        for(int i=0;i<maxn;i++) if(!deg[i]) Q.push(i);
        while(!Q.empty()){
            int f = Q.front(); Q.pop();
            for(auto v:graph[f]) {
                deg[v]--, rec[v] += rec[f], rec[v] %= mod;
                if(!deg[v]) Q.push(v);
            }
        }
        for(int i=0;i<n;i++) cout<<(i == 0 ? "" : " ")<<rec[ss[i]];cout<<endl;
    }
    return 0;
}
