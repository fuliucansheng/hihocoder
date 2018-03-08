#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool cmp(pii a, pii b){
    return a.first != b.first ? a.first < b.first : a.second > b.second;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    int n, m; cin>>n>>m;
    vector<pii> rc;
    for(int i=0;i<n;i++){
        int s, e; cin>>s>>e;
        rc.push_back(pii(s, 1)), rc.push_back(pii(e, -1));
    }
    sort(rc.begin(), rc.end(), cmp);
    set<pii> rr;
    int p = -1, c = 0;
    for(auto r:rc){
        if(r.first != p && c >= m) rr.insert(pii(p, r.first));
        p = r.first, c += r.second;
    }
    int q; cin>>q;
    for(int i=0;i<q;i++){
        int x, y; cin>>x>>y;
        auto pt = lower_bound(rr.begin(), rr.end(), pii(x,y));
        bool ans = true;
        auto pp = pt;
        if(!rr.empty() && pt != rr.begin()) pp--;
        if(pt != rr.begin() && pp->second > x) ans = false;
        if(pt != rr.end() && pt->first < y) ans = false;
        cout<<(ans ? "YES" : "NO")<<endl;
    }
    return 0;
}
