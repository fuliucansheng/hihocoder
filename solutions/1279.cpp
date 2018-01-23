#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxs = 1594323;
ll dp[2][maxs][2];
int g[2187][128][2];
bool is_valid(int s, int p){
    for(int i=0;i<13;i++){
        int rr = s % 3; s /= 3;
        if(rr == 2 && p == 0) return false;
        if(rr == 1) return false;
    }
    return true;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(dp, 0, sizeof(dp));
    int n, a = 0; cin>>n;
    for(int i=0;i<2187;i++) for(int j=0;j<128;j++) for(int p=0;p<2;p++){
                int ns = i;
                for(int k=0;k<7;k++){
                    int b = i / int(pow(3, k)) % 3;
                    if(j >> k & 1){
                        if(b != 2) ns += (b ? -1 : 1)*int(pow(3, k));
                    }else{
                        if(b == 2) ns += (p - 2)*int(pow(3, k));
                    }
                }
                g[i][j][p] = ns;
            }
    dp[0][maxs-1][0] = 1;
    for(int i=0;i<n;i++){
        memset(dp[a^1], 0, sizeof(dp[a^1]));
        int x; cin>>x;
        int bup = x/(1<<7), bdn = x%(1<<7);
        for(int s=0;s<maxs;s++)
            for(int p=0;p<2;p++)
                if(dp[a][s][p]){
                    dp[a^1][s][p] += dp[a][s][p];
                    int ns = g[s/2187][bup][p] * 2187 + g[s%2187][bdn][p];
                    dp[a^1][ns][p^1] += dp[a][s][p];
                }
        a ^= 1;
    }
    ll ans = 0;
    for(int s=0;s<maxs;s++) for(int p=0;p<2;p++) if(is_valid(s, p)) ans += dp[a][s][p];
    cout<<ans<<endl;
    return 0;
}
