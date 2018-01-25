#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
vector<int> nums;
ll dp[105][50], rc[2][50][500];
int main() {
    //freopen("../input.txt", "r" , stdin);
    string s, t; cin>>s;
    int p = 0, mx = 0;
    for(int i=0;i<int(s.size());i++) {
        if(s[i] == '+' || s[i] == '=') nums.push_back(i - p), p = i + 1, mx = max(mx, nums.back());
        if(s[i] == '=') { t = s.substr(p); break; }
    }
    if(int(t.size()) < mx) return cout<<0<<endl, 0;
    reverse(t.begin(), t.end());
    memset(rc, 0, sizeof(rc)); memset(dp, 0, sizeof(dp));
    rc[0][0][0] = rc[1][0][0] = 1;
    for(int i=1;i<=int(nums.size());i++){
        for(int j=i;j<=(9*i);j++) for(int k=1;k<=min(9,j-i+1);k++) rc[1][i][j] += rc[1][i-1][j-k], rc[1][i][j] %= mod;
        for(int j=0;j<=(9*i);j++) for(int k=0;k<=min(9,j);k++) rc[0][i][j] += rc[0][i-1][j-k], rc[0][i][j] %= mod;
    }
    dp[0][0] = 1;
    for(int i=1;i<=int(t.size());i++){
        int c1 = 0, c2 = 0;
        for(auto n:nums) c1 += (n == i), c2 += (n > i);
        for(int j=0;j<int(nums.size());j++) for(int k=0;k<int(nums.size());k++){
                int tot = t[i-1] - '0' + 10 * j - k;
                ll sum = 0;
                for(int l=c1;l<=tot;l++) sum += ll(rc[1][c1][l])*ll(rc[0][c2][tot-l]), sum %= mod;
                dp[i][j] += dp[i-1][k] * sum, dp[i][j] %= mod;
            }
    }
    cout<<dp[int(t.size())][0]<<endl;
    return 0;
}
