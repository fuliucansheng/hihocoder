#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define d(p) ds[p.first][p.second]
#define gx(vv, v) (int(lower_bound(vv.begin(), vv.end(), v) - vv.begin()))
#define vp(p) (p.first >= 0 && p.first < int(xx.size()) && xx[p.first] > 0 && xx[p.first] <= n && p.second >= 0 && p.second < int(yy.size()) && yy[p.second] > 0 && yy[p.second] <= m)
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1010;
vector<pii> nbr = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
int aa[maxn], bb[maxn], n, m, k;
ll xpre[maxn], ypre[maxn], ds[100][100];
pii obs[35], s, t;
ll bfs(pii s, pii t) {
    vector<int> xx = { s.first - 1, s.first, s.first + 1, t.first + 1, t.first, t.first + 1 }, yy = { s.second - 1, s.second, s.second + 1, t.second - 1, t.second, t.second + 1 };
    for(int i = 0; i < k; i++) {
        xx.push_back(obs[i].first - 1), xx.push_back(obs[i].first), xx.push_back(obs[i].first + 1);
        yy.push_back(obs[i].second - 1), yy.push_back(obs[i].second), yy.push_back(obs[i].second + 1);
    }
    sort(xx.begin(), xx.end()), sort(yy.begin(), yy.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end()), yy.erase(unique(yy.begin(), yy.end()), yy.end());
    set<pii> rc, vs;
    for(int i = 0; i < k; i++) rc.insert({ gx(xx, obs[i].first), gx(yy, obs[i].second) });
    pii ss = { gx(xx, s.first), gx(yy, s.second) }, tt = { gx(xx, t.first), gx(yy, t.second) };
    memset(ds, inf, sizeof(ds));
    queue<pii> Q;
    Q.push(ss), d(ss) = 0, vs.insert(ss);
    while(!Q.empty()) {
        auto f = Q.front(); Q.pop(), vs.erase(f);
        for(auto nb : nbr) {
            pii nr = pii(f.first + nb.first, f.second + nb.second);
            if(vp(nr) && !rc.count(nr)) {
                ll dd = xpre[xx[max(f.first, nr.first)]] - xpre[xx[min(f.first, nr.first)]] + ypre[yy[max(f.second, nr.second)]] - ypre[yy[min(f.second, nr.second)]];
                if((d(nr) > d(f) + dd)) {
                    d(nr) = d(f) + dd;
                    if(!vs.count(nr)) Q.push(nr), vs.insert(nr);
                }
            }
        }
    }
    return d(tt) == 0x3f3f3f3f3f3f3f3f ? -1 : d(tt);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i = 1; i < n; i++) cin>>bb[i];
    for(int i = 1; i < m; i++) cin>>aa[i];
    cin>>k;
    for(int i = 0; i < k; i++) cin>>obs[i].first>>obs[i].second;
    memset(xpre, 0, sizeof(xpre)); memset(ypre, 0, sizeof(ypre));
    for(int i = 1; i <= n; i++) xpre[i] = xpre[i - 1] + bb[i - 1];
    for(int i = 1; i <= m; i++) ypre[i] = ypre[i - 1] + aa[i - 1];
    int _; cin>>_;
    while(_--) {
        cin>>s.first>>s.second>>t.first>>t.second;
        cout<<bfs(s, t)<<endl;
    }
    return 0;
}
