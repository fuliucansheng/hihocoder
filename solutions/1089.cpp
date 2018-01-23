#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 101;
int graph[MAXN][MAXN];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(graph, 0x3f, sizeof(graph));
    int n,m,u,v,c;
    cin>>n>>m;
    for(int i=0;i<n;i++) graph[i][i] = 0;
    for(int i=0;i<m;i++) cin>>u>>v>>c, graph[v-1][u-1] = graph[u-1][v-1] = min(graph[u-1][v-1], c);
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++) cout<<graph[i][j]<<" ";
        cout<<graph[i][n-1]<<endl;
    }
    return 0;
}
