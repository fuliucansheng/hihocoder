#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1<<21];
int n, m;
bool vis[1<<21];
inline int idx(int a, int b){
    return a * m + b;
}
unordered_set<int> get_nbr(int s){
    unordered_set<int> ret;
    for(int ss = s; ss != 0; ss -= (ss & -ss)){
        int x = int(log2(ss & -ss));
        int a = x / m, b = x % m;
        if(a + 1 < n && (s & (1 << idx(a + 1, b))) == 0) ret.insert(s | (1 << idx(a + 1, b)));
        if(a - 1 >= 0 && (s & (1 << idx(a - 1, b))) == 0) ret.insert(s | (1 << idx(a - 1, b)));
        if(b + 1 < m && (s & (1 << idx(a, b + 1))) == 0) ret.insert(s | (1 << idx(a, b + 1)));
        if(b - 1 >= 0 && (s & (1 << idx(a, b - 1))) == 0) ret.insert(s | (1 << idx(a, b - 1)));
    }
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dp, 0, sizeof(dp)); memset(vis, 0, sizeof(vis));
    cin>>n>>m;
    int s = 0, t = (1 << (n * m)) - 1;
    for(int i=0;i<n;i++){
        string ss; cin>>ss;
        for(int j=0;j<m;j++) s |= ((ss[j] == '1') << idx(i, j));
    }
    dp[s] = 1;
    queue<int> Q;
    Q.push(s), vis[s] = true;
    while(!Q.empty()){
        int f = Q.front(); Q.pop();
        unordered_set<int> nbr = get_nbr(f);
        for(auto nr:nbr) {
            dp[nr] += dp[f];
            if(!vis[nr]) Q.push(nr), vis[nr] = true;
        }
        if(f != t) dp[f] = 0; //加上这个更好理解
        vis[f] = false;
    }
    cout<<dp[t]<<endl;
    return 0;
}
