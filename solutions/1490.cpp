#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 105;
int dis[maxn][maxn], dct[maxn], hgt[maxn], vis[maxn], leaf[maxn], fa[maxn], m, n, k, ne;
vector<int> dep[maxn];
void disup(int u, int fa){
    for(int i=0;i<maxn;i++) if(dis[u][i] != -1) dis[i][fa] = dis[fa][i] = dis[u][i] - 1;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dis, -1, sizeof(dis)); memset(vis, 0, sizeof(vis));
    cin>>n>>m>>k;
    queue<int> Q;
    for(int i=0;i<m;i++) cin>>dct[i];
    for(int i=0;i<m;i++) for(int j=0;j<dct[i];j++) cin>>ne, dep[i].push_back(ne), hgt[ne] = i;
    for(int i=0;i<k;i++) cin>>leaf[i], vis[leaf[i]] = 1;
    for(int i=0;i<k;i++) for(int j=0;j<k;j++) cin>>dis[leaf[i]][leaf[j]];
    for(int i=m-1;i>0;i--){
        int fp = 0; while(vis[dep[i-1][fp]]) fp++;
        fa[dep[i][0]] = dep[i-1][fp], disup(dep[i][0], dep[i-1][fp]);
        for(int j=1;j<dep[i].size();j++){
            int f = dep[i][j], p = dep[i][j-1];
            if(dis[p][f] == 2) fa[f] = dep[i-1][fp], disup(f, fa[f]);
            else {
                while(vis[dep[i-1][++fp]]);
                fa[f] = dep[i-1][fp], disup(f, fa[f]);
                vis[dep[i-1][fp]] = 1;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<fa[i]<<" "; cout<<endl;
    return 0;
}
