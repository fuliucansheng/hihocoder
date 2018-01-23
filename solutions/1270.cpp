#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxm = 101, maxk = 10010;
ll arrb[maxm], arra[maxm], dp[maxm][maxk];
int main(){
    //freopen("../input.txt","r",stdin);
    int _; cin>>_;
    while(_--){
        ll m, n, k, t; cin>>n>>m>>k>>t;
        memset(arrb, 0, sizeof(arrb));
        for(int i=0;i<m;i++) cin>>arra[i];
        for(int i=0;i<m;i++) cin>>arrb[i];
        ll ans = 0;
        for(int i=0;i<n;i++){
            memset(dp, -1, sizeof(dp));
            for(int j=0;j<m;j++) dp[j][0] = 0;
            for(int j=0;j<m;j++)
                for(int p=0;p<=k;p++)
                    if(dp[j][p] != -1) {
                        dp[j+1][p] = (dp[j+1][p] != -1 ? min(dp[j+1][p], dp[j][p]) : dp[j][p]);
                        dp[j][min(k,p+arrb[j])] = (dp[j][min(k,p+arrb[j])] != -1 ? min(dp[j][min(k,p+arrb[j])], dp[j][p] + arra[j]) : dp[j][p] + arra[j]);
                    }
            if(dp[m][k] != -1) ans += dp[m][k];
            else { ans = -1, cout<<"No Answer"<<endl; break; }
            for(int j=0;j<m;j++) arrb[j] /= t;
        }
        if(ans >= 0) cout<<ans<<endl;
    }
    return 0;
}
