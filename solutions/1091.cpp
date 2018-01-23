#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 35, maxm = 20005;
int cost[maxn][maxm], dmg[maxn][maxm], rec[maxm];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(cost, 0, sizeof(cost));memset(dmg, 0, sizeof(dmg));memset(rec, 0, sizeof(rec));
    int n,m,a,b,t;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        t = cost[i][1] = b;dmg[i][1] = a;
        for(int j=2;;j++) {
            t = 1.07*t, cost[i][j] = cost[i][j-1] + t, dmg[i][j] = a*j;
            if(cost[i][j] > m) { cost[i][0] = j;break;}
        }
    }
    for(int i=0;i<n;i++){
        for(int j=m;j>=0;j--){
            for(int k=1;k<cost[i][0];k++) {
                if(j >= cost[i][k]) rec[j] = max(rec[j], rec[j-cost[i][k]] + dmg[i][k]);
                else break;
            }
        }
    }
    cout<<rec[m]<<endl;
    return 0;
}
