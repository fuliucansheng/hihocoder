#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mz(p) maze[p.first][p.second]
#define px(p) p.first*m+p.second
#define vp(p) (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m)
typedef pair<int,int> pii;
vector<pii> nbr = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int dp[1<<21][6], n, m, hp, ap, msz = 0;
string maze[10];
map<pii,int> dict;
pii mon_hap[10], s;
int dfs(int vs, int r, int c){
    if(c == msz) return 0;
    if(dp[vs][r] < inf) return dp[vs][r];
    set<pii> nb;
    for(int i=0;i<(n*m);i++) if((1<<i)&vs){
            for(auto nn:nbr){
                pii nr = pii(i/m+nn.first, i%m+nn.second);
                if(vp(nr) && !((1<<(px(nr)))&vs)) nb.insert(nr);
            }
        }
    int rs = inf;
    for(auto nr:nb){
        int nvs = vs | (1<<(px(nr)));
        if(mz(nr) == 'M' || mz(nr) == 'S'){
            int rr = r-1, rq = 0, mhp = mon_hap[dict[nr]].first, map = mon_hap[dict[nr]].second;
            while(mhp > 0){
                if(rr <= 0) rq += map;
                mhp -= ap, rr--;
            }
            if(rq >= hp) return 0;
            if(mz(nr) == 'S') rr = 5;
            rs = min(rs, rq + dfs(nvs, rr > 0 ? rr : 0, c + 1));
        }else rs = min(rs, dfs(nvs, (r-1) > 0 ? (r-1) : 0, c));
    }
    dp[vs][r] = rs;
    return rs;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>maze[i];
        for(int j=0;j<m;j++) if(maze[i][j] == 'M' || maze[i][j] == 'S') dict[pii(i,j)] = ++msz;
        else if(maze[i][j] == 'D') s.first = i, s.second = j;
    }
    for(int i=1;i<=msz;i++) cin>>mon_hap[i].first>>mon_hap[i].second;
    cin>>hp>>ap;
    memset(dp, inf, sizeof(dp));
    int ans = dfs(1<<px(s), 5, 0);
    if(ans < hp) cout<<hp - ans<<endl; else cout<<"DEAD"<<endl;
    return 0;
}
