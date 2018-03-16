#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    string a,b;
    cin>>a>>b;
    int dp[a.size()+1][b.size()+1];
    memset(dp, 0, sizeof(dp));
    for(int i=a.size()-1;i>=0;i--){
        for(int j=b.size()-1;j>=0;j--){
            int r = 0, k = 0;
            while((i+k+1)<=a.size() && (j+k+1)<=b.size() && a[i+k] == b[j+k]) {
                if(k >= 2) r = max(r, k+1+dp[i+k+1][j+k+1]);
                k++;
            }
            dp[i][j] = max({r, dp[i+1][j], dp[i][j+1]});
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}
