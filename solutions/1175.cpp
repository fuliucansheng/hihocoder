#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e5+50, mod = 142857;
vector<int> graph[maxn];
int virus[maxn], active[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(virus, 0, sizeof(virus));memset(active, 0, sizeof(active));
    int n,m,k,u,v,r,node;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++) cin>>r, virus[r]++;
    for(int i=0;i<m;i++) cin>>u>>v, graph[u].push_back(v), active[v]++;
    queue<int> Q;
    for(int i=1;i<=n;i++) if(active[i] == 0) Q.push(i);
    while(!Q.empty()){
        node = Q.front();Q.pop();
        for(auto e:graph[node]) {
            active[e]--, virus[e] += virus[node], virus[e] %= mod;
            if(active[e] == 0) Q.push(e);
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++) res += virus[i], res %= mod;
    cout<<res<<endl;
    return 0;
}
