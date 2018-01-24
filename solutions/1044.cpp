#include <iostream>
#include <cstring>
using namespace std;
const int N = 1<<10;
int dp[1001][N];
int count(int k){
    int res = 0;
    while(k > 0) res += (k&1),k >>= 1;
    return res;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(dp,0,sizeof(dp));
    int m,n,q,num;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>num;
        for(int j=0;j<=(1<<m);j++){
            if(count(j) > q) continue;
            if(j&1) dp[i][j] = max(dp[i-1][j>>1],dp[i-1][(j>>1)+(1<<m-1)]) + num;
            else dp[i][j] = max(dp[i-1][j>>1],dp[i-1][(j>>1)+(1<<m-1)]);
        }
    }
    int maxres = 0;
    for(int i=0;i<=(1<<m);i++) maxres = max(maxres,dp[n][i]);
    cout<<maxres<<endl;
    return 0;
}
