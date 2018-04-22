#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define vp(p) (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m)
#define a(p) arr[p.first][p.second]
#define d(p) ds[p.first][p.second]
#define v(p) vs[p.first][p.second]
typedef pair<int,int> pii;
const int maxn = 101;
int ds[maxn][maxn], n, m;
string arr[maxn];
bool vs[maxn][maxn];
vector<pii> nbr = { pii(-1, 0), pii(1, 0), pii(0, -1), pii(0, 1) };
int bfs(pii s) {
    memset(vs, 0, sizeof(vs)); memset(ds, inf, sizeof(ds));
    v(s) = true, d(s) = 0;
    queue<pii> Q; Q.push(s);
    int ret = inf;
    while(!Q.empty()) {
        pii f = Q.front(); Q.pop();
        for(auto nb:nbr) {
            pii nr = pii(f.first + nb.first, f.second + nb.second);
            if(a(f) == 'S' && vp(nr) && a(nr) == 'S' && d(nr) != inf) ret = min(ret, d(f) + d(nr));
            if(a(f) != 'S' && vp(nr) && !v(nr) && (a(nr) == '.' || a(nr) == 'S')) Q.push(nr), v(nr) = true, d(nr) = d(f) + 1;
        }
    }
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    pii s;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        auto x = find(arr[i].begin(), arr[i].end(), 'H');
        if(x != arr[i].end()) s.first = i, s.second = int(x - arr[i].begin());
    }
    int ans = bfs(s);
    if(ans == inf) cout<<"Hi and Ho will not have lunch."<<endl;
    else cout<<ans<<endl;
    return 0;
}