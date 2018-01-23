#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 205;
vector<int> graph[maxn];
ll arr[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int m, n; cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    int rs = 0;
    while(rs < 100000){
        ll r = -1, d = 0;
        for(int i=0;i<n;i++){
            ll sz = ll(graph[i].size());
            if(arr[i] >= sz && (r == -1 || arr[i] - sz > d)) r = i, d = arr[i] - sz;
        }
        if(r == -1) break;
        arr[r] -= ll(graph[r].size());
        for(auto v:graph[r]) arr[v]++;
        rs++;
    }
    if(rs < 100000) cout<<rs<<endl; else cout<<"INF"<<endl;
    return 0;
}
