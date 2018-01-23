#include <iostream>
#include <cstring>
using namespace std;
#define inf 0x3f3f3f3f
int dp[55][55][55][5][5][5];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(dp, inf, sizeof(dp));
    dp[1][0][0][0][0][3] = 1; dp[0][1][0][1][0][3] = 1; dp[0][0][1][2][0][3] = 1;
    for(int n=0;n<=50;n++) for(int m=0;m<=50;m++) for(int k=0;k<=50;k++)
                for(int x=0;x<3;x++) for(int y=0;y<3;y++) for(int z=1;z<=3;z++){
                            if(dp[n][m][k][x][y][z] != inf){
                                for(int d=0;d<3;d++){
                                    int nn = n, mm = m, kk = k;
                                    if(d == 0) nn++;
                                    if(d == 1) mm++;
                                    if(d == 2) kk++;
                                    int zz = z + max(x, d) + 2;
                                    if(zz > 3) zz = 3;
                                    dp[nn][mm][kk][d][y][zz] = min(dp[nn][mm][kk][d][y][zz], dp[n][m][k][x][y][z] + max(x, d) + 2);
                                    zz = max(1, max(y, d)+2-z);
                                    if(zz > 3) zz = 3;
                                    dp[nn][mm][kk][d][x][zz] = min(dp[nn][mm][kk][d][x][zz], dp[n][m][k][x][y][z] + zz);
                                }
                            }
                        }
    dp[0][0][0][0][0][1] = 0;
    int q; cin>>q;
    while(q--){
        int m, n, k; cin>>n>>m>>k;
        int ans = inf;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int p=1;p<=3;p++) ans = min(ans, dp[n][m][k][i][j][p]);
        cout<<ans<<endl;
    }
    return 0;
}
