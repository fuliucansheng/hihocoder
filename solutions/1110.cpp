#include <bits/stdc++.h>
using namespace std;
bool solve(string s){
    bool dp[s.size()][s.size()];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<s.size();i++) dp[i][i] = (s[i] == '0' || s[i] == '1');
    for(int i=s.size()-1;i>=0;i--){
        for(int j=i+1;j<s.size();j++){
            if(s[j] == '*') dp[i][j] = (dp[i][j] | dp[i][j-1]);
            if(s[i] == '(' && s[j] == ')') dp[i][j] = (dp[i][j] | dp[i+1][j-1]);
            for(int k=i;k<j;k++){
                if(s[k] == '|') dp[i][j] = (dp[i][j] | (dp[i][k-1] && dp[k+1][j]));
                else dp[i][j] = (dp[i][j] | (dp[i][k] && dp[k+1][j]));;
            }
        }
    }
    return dp[0][s.size()-1];
}
int main(){
    //freopen("../input.txt","r",stdin);
    string s;
    while(cin>>s) cout<<(solve(s) ? "yes" : "no")<<endl;
    return 0;
}
