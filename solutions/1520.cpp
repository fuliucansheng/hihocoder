#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    string s; cin>>s;
    int sz = int(s.size()), x, y; cin>>x>>y;
    int rc[sz] = { 0 }, mo = 0;
    vector<int> pp;
    for(int i=0;i<sz;i++) {
        rc[i] = i > 0 ? (rc[i-1] * 10 % x) : 1;
        if(s[sz - i - 1] == '?') {
            if(i == (sz - 1)) mo += rc[i], mo %= x;
            pp.push_back(i);
        }
        else mo += rc[i] * (s[sz - i -1] - '0'), mo %= x;
    }
    mo = (y - mo) % x, mo = (mo + x) % x;
    int ppz = int(pp.size());
    int dp[ppz + 1][x], vs[ppz + 1][x];
    for(int i=0;i<=ppz;i++) for(int j=0;j<x;j++) vs[i][j] = 0, dp[i][j] = 0;
    vs[0][0] = 1;
    for(int i=0;i<ppz;i++) for(int k=0;k<10;k++) for(int j=0;j<x;j++) if(vs[i][j]){
                    int nj = (j + k * rc[pp[i]]) % x;
                    if(!vs[i+1][nj]) dp[i+1][nj] = k, vs[i+1][nj] = true;
            }
    if(!vs[ppz][mo]) cout<<"No solution"<<endl;
    else{
        int mmo = mo;
        for(int i=ppz-1;i>=0;i--){
            s[sz - pp[i] - 1] = char(dp[i+1][mmo] + '0');
            mmo = (mmo - dp[i+1][mmo] * rc[pp[i]]) % x, mmo = (mmo + x) % x;
        }
        if(pp.back() == (sz - 1)) s[0]++;
        if(s[0] <= '9') cout<<s<<endl; else cout<<"No solution"<<endl;
    }
    return 0;
}
