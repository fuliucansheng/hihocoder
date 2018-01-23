#include <iostream>
using namespace std;
const int maxn = 101;
int dp[maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    for(int i=0;i<s.size();i++) dp[i][i] = 0;
    for(int i=s.size()-1;i>=0;i--)
        for(int j=i+1;j<s.size();j++){
            int tp = (j-i > 1 ? dp[i+1][j-1] : 0);
            if(s[i] == s[j]) dp[i][j] = tp;
            else dp[i][j] = min(tp, min(dp[i][j-1], dp[i+1][j])) + 1;
        }
    cout<<dp[0][s.size()-1]<<endl;
    return 0;
}
