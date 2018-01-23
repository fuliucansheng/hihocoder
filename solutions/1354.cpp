#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f
#define v(p) vis[p.first][p.second]
#define d(p) dis[p.first][p.second]
#define vp(p) (p.first > 0 && p.first <= n && p.second > 0 && p.second <= m)
typedef pair<int,int> pii;
const int maxn = 505;
pii rec[35];
int dis[maxn][maxn], a[maxn], b[maxn], m, n, k;
bool vis[maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i=1;i<n;i++) cin>>b[i];
    for(int i=1;i<m;i++) cin>>a[i];
    cin>>k;
    for(int i=0;i<k;i++) cin>>rec[i].first>>rec[i].second;
    int _; cin>>_;
    while(_--){
        int x, y, p, q; cin>>x>>y>>p>>q;
        memset(vis, 0, sizeof(vis)); memset(dis, inf, sizeof(dis));
        for(int i=0;i<k;i++) v(rec[i]) = true;
        pii s = pii(x, y), t = pii(p, q);
        queue<pii> Q;
        Q.push(s), v(s) = true, d(s) = 0;
        while(!Q.empty()){
            pii f = Q.front(); v(f) = true;
            pii nt = pii(f.first - 1, f.second), nb = pii(f.first + 1, f.second), nl = pii(f.first, f.second - 1), nr = pii(f.first, f.second + 1);
            if(vp(nt) && d(nt) > d(f) + b[nt.first]) {
                d(nt) = d(f) + b[nt.first];
                if(!v(nt)) Q.push(nt), v(nt) = true;
            }
            if(vp(nb) && d(nb) > d(f) + b[f.first]) {
                d(nb) = d(f) + b[f.first];
                if(!v(nb)) Q.push(nb), v(nb) = true;
            }
            if(vp(nl) && d(nl) > d(f) + a[nl.second]) {
                d(nl) = d(f) + a[nl.second];
                if(!v(nl)) Q.push(nl), v(nl) = true;
            }
            if(vp(nr) && d(nr) > d(f) + a[f.second]) {
                d(nr) = d(f) + a[f.second];
                if(!v(nr)) Q.push(nr), v(nr) = true;
            }
            v(f) = false, Q.pop();
        }
        if(d(t) == inf) cout<<-1<<endl; else cout<<d(t)<<endl;
    }
    return 0;
}
