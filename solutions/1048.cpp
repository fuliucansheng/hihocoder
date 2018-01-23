#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e9+7;
int n,m;
int flag(int state){
    for(int s=0;s<m;s++){
        if((state&(1<<s)) == 0) return s;
    }
    return m;
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m;
    int sc = (1<<(2*m)),sh = (1<<m);
    int dp[sc];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<sh;j++){
            for(int k=0;k<=j;k++){
                int currstate = ((k<<m)|j);
                int f = flag(j);
                int nextstatehor = 0,nextstatever = 0;
                if(f<(m-1)&&(((1<<(f+1))&currstate) == 0)) nextstatehor = (currstate|(1<<(f+1))|(1<<f));
                if(f<m&&i<(n-1)&&(((1<<f)&k) == 0)) nextstatever = (currstate|(1<<(f+m)|(1<<f)));
                if(nextstatehor > 0) dp[nextstatehor] += dp[currstate],dp[nextstatehor]%=N;
                if(nextstatever > 0) dp[nextstatever] += dp[currstate],dp[nextstatever]%=N;
                if(i == 0 && j == 0) dp[nextstatehor] = 1,dp[nextstatever] = 1;
            }
        }
        for(int s=0;s<sc;s++){
            if(s < sh) dp[s] = dp[((sh-1)|(s<<m))];
            else dp[s] = 0;
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}
