#include <iostream>
#include <cstring>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 105;
int arr[40][maxn][maxn], dis[2][maxn], m, n, mxi, mxk;
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(arr, inf, sizeof(arr));
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[0][i][j];
    for(int i=0;i<n;i++) arr[0][i][i] = inf;
    for(int i=2,k=1;i<=m;i<<=1,k++){
        mxi = i, mxk = k;
        for(int z=0;z<n;z++) for(int x=0;x<n;x++) for(int y=0;y<n;y++) arr[k][x][y] = min(arr[k][x][y], arr[k-1][x][z] + arr[k-1][z][y]);
    }
    int rs = 0;
    for(int i=mxi,k=mxk;i;i>>=1,k--){
        bool status = false;
        for(int j=0;j<n;j++) dis[1][j] = inf;
        for(int j=0;j<n;j++)
            for(int x=0;x<n;x++) {
                if(dis[1][j] > dis[0][x] + arr[k][x][j]){
                    dis[1][j] = dis[0][x] + arr[k][x][j];
                    if(dis[1][j] <= m) status = true;
                }
            }
        if(status) rs += i, memcpy(dis[0], dis[1], sizeof(dis[0]));
    }
    cout<<rs<<endl;
    return 0;
}

