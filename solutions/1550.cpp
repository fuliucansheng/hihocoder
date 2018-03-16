#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    ll dp[4] = { 0 };
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(x == 1) dp[1]++;
        if(x == 2) dp[2] += dp[1];
        if(x == 3) dp[3] += dp[2];
    }
    cout<<dp[3]<<endl;
    return 0;
}