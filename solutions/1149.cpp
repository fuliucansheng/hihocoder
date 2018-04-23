#include <bits/stdc++.h>
using namespace std;
const int mod = 100007;
int solve(string s){
    int sz = s.size();
    int dp[sz][sz];
    memset(dp, 0, sizeof(dp));
    for(int i = sz - 1; i >= 0; i--){
        for(int j = i; j < sz; j++){
            if(i == j) dp[i][j] = 1;
            else{
                int pre = dp[i][j-1], suf = dp[i+1][j], com = dp[i+1][j-1];
                dp[i][j] = ((pre + suf - com)%mod + mod)%mod;
                if(s[i] == s[j]) dp[i][j] += com + 1;
                dp[i][j] %= mod;
            }
        }
    }
    return dp[0][sz - 1];
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    string s;
    for(int i = 1; i <= t; i++){
        cin>>s;
        cout<<"Case #"<<i<<": "<<solve(s)<<endl;
    }
    return 0;
}
