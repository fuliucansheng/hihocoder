#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
unordered_map<string,int> dict;
vector<int> graph[maxn];
bool fiter[maxn];
string ss[maxn];
int dp[maxn];
bool cmp(int a, int b){
    int al = 0, bl = 0, ar = int(ss[a].size()) - 1, br = int(ss[b].size()) - 1;
    while(al < ar && bl < br && ss[a][al] == ss[b][bl]) al++, bl++;
    while(al < ar && bl < br && ss[a][ar] == ss[b][br]) ar--, br--;
    return al == ar && (ss[a][al] == ss[b][bl] || ss[a][al] == ss[b][br]) && br - bl == 1;
}
int dfs(int u){
    if(dp[u] != -1) return dp[u];
    int ret = 0;
    for(auto v:graph[u]) ret = max(ret, dfs(v));
    dp[u] = ret + 1;
    return ret + 1;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    memset(fiter, 0, sizeof(fiter)); memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    string s; cin>>s;
    for(int i=1;i<=n;i++) {
        cin>>ss[i];
        if(ss[i].size() > n || dict.count(ss[i])) fiter[i] = true;
        if(!dict.count(ss[i])) dict[ss[i]] = i;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(!fiter[i] && !fiter[j]) {
                if(ss[i].size() == ss[j].size() - 1 && cmp(i, j)) graph[dict[ss[i]]].push_back(dict[ss[j]]);
                else if(ss[i].size() - 1 == ss[j].size() && cmp(j, i)) graph[dict[ss[j]]].push_back(dict[ss[i]]);
            }
    int ans = dfs(dict[s]);
    cout<<ans<<endl;
    return 0;
}
