#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define v(p) vis[p.first][p.second]
#define a(p) arr[p.first][p.second]
#define vd(p) (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m)
typedef pair<int,int> ps;
const int maxn = 505;
vector<ps> nbr = {ps(-1,0), ps(1,0), ps(0,1), ps(0,-1)};
int vis[maxn][maxn], scc_cnt = 1,m, n;
string arr[maxn];
set<pair<ps,pair<ps,ps>>> rs;
void dfs(ps s, int ct){
    queue<ps> Q;
    Q.push(s), v(s) = ct;
    int l = s.second, r = s.second, t = s.first, b = s.first;
    ps ss = ps(s.second, s.first);
    while(!Q.empty()){
        ps f = Q.front(); Q.pop();
        l = min(l, f.second), r = max(r, f.second), t = min(t, f.first), b = max(b, f.first);
        if(f.second < ss.first || (f.second == ss.first && f.first < ss.second)) ss.first = f.second, ss.second = f.first;
        for(auto nb:nbr){
            ps nr = ps(f.first+nb.first, f.second+nb.second);
            if(vd(nr) && !v(nr) && a(nr) == '1') Q.push(nr), v(nr) = ct;
        }
    }
    rs.insert(make_pair(ss, make_pair(ps(t,l), ps(b-t+1,r-l+1))));
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(vis, 0, sizeof(vis));
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!v(ps(i,j)) && a(ps(i,j)) == '1') dfs(ps(i,j), scc_cnt++);
    for(auto r:rs){
        ps s = r.first, c = r.second.first, e = r.second.second;
        cout<<e.first<<" "<<e.second<<endl;
        int t = v(ps(s.second,s.first)), dx = c.first, dy = c.second;
        for(int i=0;i<e.first;i++){
            for(int j=0;j<e.second;j++)
                if(a(ps(dx+i, dy+j)) == '1' && v(ps(dx+i, dy+j)) == t) cout<<1;
                else cout<<0;
            cout<<endl;
        }
    }
    return 0;
}
