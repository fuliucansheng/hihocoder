#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int group[maxn];
set<int> rc[maxn];
int find_group(int x){
    return group[x] == x ? x : group[x] = find_group(group[x]);
}
void union_group(int x, int u, int v){
    int du = find_group(u), dv = find_group(v);
    if(du != dv) {
        if(du > dv) swap(du, dv);
        if(x == 0) {
            group[dv] = du;
            for(auto vv:rc[dv]) rc[du].insert(find_group(vv));
        }else rc[dv].insert(du), rc[du].insert(dv);
    }
}
int query(int u, int v) {
    int du = find_group(u), dv = find_group(v);
    if(du == dv) return 1;
    if(rc[du].count(dv) || rc[dv].count(du)) return 2;
    return 3;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    for(int i=0;i<maxn;i++) group[i] = i;
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++) {
        char op; cin>>op;
        int x, y, r;
        if(op == 'R') {
            cin>>x>>y>>r;
            union_group(r - 1, x, y);
        }else {
            cin>>x>>y;
            cout<<query(x, y)<<endl;
        }
    }
    return 0;
}
