#include <bits/stdc++.h>
using namespace std;
int cnt, n;
int rc[10][10], co[10][10], arr[10];
bool vis[10];
void dfs(int x){
    if(x > 4){
        int c = 0;
        for(int i=1;i<x-1;i++) c += co[arr[i]][arr[i+1]];
        if(c == n) cnt++;
    }
    for(int i=1;i<10;i++) if(!vis[i]){
            if(rc[arr[x-1]][i] && !vis[rc[arr[x-1]][i]]) continue;
            vis[i] = true, arr[x] = i;
            dfs(x+1);
            vis[i] = false;
        }
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t, l, r;
    cin>>t;
    memset(rc, 0, sizeof(rc));
    rc[1][3] = 2, rc[1][7] = 4, rc[1][9] = 5, rc[2][8] = 5;
    rc[3][7] = 5, rc[3][9] = 6, rc[4][6] = 5, rc[7][9] = 8;
    for(int i = 1;i < 10;i++) for(int j=i+1;j<10;j++) rc[j][i] = rc[i][j];
    while(t--){
        cin>>n;
        memset(co, 0, sizeof(co)); memset(vis, 0, sizeof(vis));
        for(int i=0;i<n;i++) cin>>l>>r, co[l][r] = 1, co[r][l] = 1;
        cnt = 0;
        dfs(1);
        cout<<cnt<<endl;
    }
    return 0;
}