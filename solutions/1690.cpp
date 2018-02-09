#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("../input.txt", "r" , stdin);
    string s; cin>>s;
    int dp[5] = { 0 };
    for(auto c:s){
        if(c == 'a') dp[0]++;
        if(c == 'e') dp[1] = max(dp[0], dp[1]) + 1;
        if(c == 'i') dp[2] = max({dp[0], dp[1], dp[2]}) + 1;
        if(c == 'o') dp[3]++;
        if(c == 'u') dp[4] = max(dp[3], dp[4]) + 1;
    }
    cout<<max({dp[0], dp[1], dp[2]})+max(dp[3], dp[4])<<endl;
    return 0;
}
