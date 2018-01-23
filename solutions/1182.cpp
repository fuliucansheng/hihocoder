#include <iostream>
#include <vector>
using namespace std;
const int maxn = (1<<16);
vector<int> graph[maxn];
vector<bool> vis[maxn];
int pt[maxn], pz = 0, n;
void dfs(int u){
    for(int i=0;i<graph[u].size();i++) if(!vis[u][i]) vis[u][i] = true, dfs(graph[u][i]);
    pt[pz++] = (u&1) != 0;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        int pre = (i>>1), suf = i&((1<<(n-1))-1);
        graph[pre].push_back(suf), vis[pre].push_back(false);
    }
    if(n == 1) return cout<<0<<1<<endl, 0;
    dfs(0);
    for(int i=0;i<(1<<n);i++) cout<<pt[i];
    return 0;
}
