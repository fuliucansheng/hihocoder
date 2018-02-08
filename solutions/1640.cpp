#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("../input.txt", "r" , stdin);
    int n; cin>>n;
    string s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    bool v[n]; memset(v, 0, sizeof(v));
    vector<string> arr;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if((i != j) && !v[i] && !v[j] && (search(s[i].begin(), s[i].end(), s[j].begin(), s[j].end()) != s[i].end())) v[j] = true;
    for(int i=0;i<n;i++) if(!v[i]) arr.push_back(s[i]);
    int sz = int(arr.size());
    int ps[sz][sz], dp[1<<sz][sz], ssz = 1<<sz;
    for(int i=0;i<sz;i++) for(int j=0;j<sz;j++){
            int rs = 0, isz = int(arr[i].size()), jsz = int(arr[j].size());
            for(int k=0;k<isz;k++){
                int r = 0;
                while((k+r) < isz && r < jsz && arr[i][k+r] == arr[j][r]) r++;
                if((k+r) == isz) rs = max(rs, r);
            }
            ps[i][j] = rs;
        }
    memset(dp, 0x3f, sizeof(dp));
    for(int i=0;i<sz;i++) dp[1<<i][i] = int(arr[i].size());
    for(int i=0;i<ssz;i++) for(int j=0;j<sz;j++) if(dp[i][j] != 0x3f3f3f3f){
                for(int k=0;k<sz;k++) if(!(i>>k&1)) dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k], dp[i][j] + int(arr[k].size()) - ps[j][k]);
            }
    int ans = INT32_MAX;
    for(int i=0;i<sz;i++) ans = min(ans, dp[ssz-1][i]);
    cout<<ans<<endl;
    return 0;
}
