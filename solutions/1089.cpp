#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
int dis[maxn][maxn], n, m, u, v, c;
int main(){
    //freopen("../input.txt","r",stdin);
    memset(dis, 0x3f, sizeof(dis));
    cin>>n>>m;
    for(int i=0;i<n;i++) dis[i][i] = 0;
    for(int i=0;i<m;i++) cin>>u>>v>>c, dis[v-1][u-1] = dis[u-1][v-1] = min(dis[u-1][v-1], c);
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<dis[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}