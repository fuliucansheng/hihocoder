#include <bits/stdc++.h>
using namespace std;
#define dx(c) c-'a'
int m, n;
string s;
bool rec[26][26];
int dp[26];
int main() {
    //freopen("../input.txt", "r", stdin);
    memset(rec, 0, sizeof(rec)); memset(dp, 0, sizeof(dp));
    cin>>n>>s>>m;
    char u, v;
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        rec[dx(u)][dx(v)] = rec[dx(v)][dx(u)] = true;
    }
    for(int i=0;i<int(s.size());i++){
        int x = dx(s[i]), r = 0;
        for(int j=0;j<26;j++) if(!rec[x][j]) r = max(r, dp[j]);
        dp[x] = max(dp[x], r + 1);
    }
    int rs = 0;
    for(int i=0;i<26;i++) rs = max(rs, dp[i]);
    cout<<(n - rs)<<endl;
    return 0;
}
