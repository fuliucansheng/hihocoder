#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 105;
int dp[maxn][maxn], sz;
string s;
vector<int> nextarr(string patt){
    vector<int> result(patt.size() + 1, 0);
    for (int i = 1; i < patt.size(); i++) {
        int j = result[i];
        while (j && patt[i] != patt[j]) j = result[j];
        result[i + 1] = patt[i] == patt[j] ? j + 1 : 0;
    }
    return result;
}
int g(int l, int r){
    int len = r - l + 1;
    if(len <= 4) return len;
    string ss = s.substr(l, len);
    vector<int> nxt = nextarr(ss);
    if(nxt[len] && len%(len-nxt[len]) == 0) return 2 + int(to_string(len/(len-nxt[len])).size()) + dp[l][l+(len-nxt[len])-1];
    return len;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        cin>>s;
        sz = int(s.size()), memset(dp, inf, sizeof(dp));
        for(int i=0;i<sz;i++) dp[i][i] = 1;
        for(int l=1;l<=sz;l++) for(int i=0;i+l<sz;i++) {
                int j = i + l, c = inf;
                for(int k=i;k<j;k++) c = min(c, dp[i][k] + dp[k+1][j]);
                dp[i][j] = min(min(l + 1, c), g(i, j));
            }
        cout<<dp[0][sz-1]<<endl;
    }
    return 0;
}
