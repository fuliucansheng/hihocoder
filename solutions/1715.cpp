#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
vector<int> graph[maxn];
int ds[maxn], n;
ll ans = 0;
void region_upd(set<int> &rc, int s){
    auto p = rc.insert(s).first;
    auto pn = p, ppn = p;
    while(true){
        auto pp = p; pp++;
        if(pp == rc.end() || (ds[*p] < *pp - 1)) break;
        ds[*p] = ds[*pp], rc.erase(pp);
    }
    if(pn != rc.begin()) {
        pn--;
        if(ds[*pn] == *ppn - 1) ds[*pn] = ds[*ppn], rc.erase(ppn);
    }
}
set<int> dfs(int u, int f = 0){
    set<int> uu = { u }; ds[u] = u;
    for(auto v:graph[u]) if(v != f){
            set<int> vv = dfs(v, u);
            int a = 0, b = *vv.begin() - 1;
            auto p = vv.begin(), pp = vv.begin(); pp++;
            while(pp != vv.end()){
                ans += ll(ds[*p] - *p + 1) * ll(a) + ll(*pp - ds[*p] - 1) * ll(b);
                a += ds[*p] - *p + 1, b += *pp - ds[*p] - 1;
                region_upd(uu, *p);
                p++, pp++;
            }
            ans += ll(ds[*p] - *p + 1) * ll(a) + ll(n - ds[*p]) * ll(b);
            a += ds[*p] - *p + 1, b += n - ds[*p];
            ans += ll(a) * ll(b);
            region_upd(uu, *p);
        }
    return uu;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=1;i<n;i++) {
        int x, y; cin>>x>>y;
        graph[x].push_back(y), graph[y].push_back(x);
    }
    dfs(1, 0);
    cout<<ans<<endl;
    return 0;
}
