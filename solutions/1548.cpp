#include <bits/stdc++.h>
using namespace std;
#define d(a, b) (abs(a.first - b.first) + abs(a.second - b.second))
#define vp(p) (p.first >= 0 && p.first <= n && p.second >= 0 && p.second <= m)
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
vector<pii> nbr = { pii(-1,-1), pii(-1,0), pii(-1,1), pii(0,-1), pii(0,1), pii(1,-1), pii(1,0), pii(1,1) };
int n, m, k, q;
pii arr[10], s, t;
bool is_valid(pii p){
    for(int i=0;i<=q;i++) if(d(p, arr[i]) < k) return false;
    return true;
}
bool solve(){
    priority_queue<pip> Q;
    if(!is_valid(s) || !is_valid(t)) return false;
    if(s == t) return true;
    set<pii> vis;
    Q.push(pip(-d(s,t), s)), vis.insert(s);
    int cnt = 0;
    while(!Q.empty()){
        pip f = Q.top(); Q.pop(), cnt++;
        if(cnt > 5e4) return false;
        for(auto nb:nbr){
            pip nr = pip(0, pii(f.second.first + nb.first, f.second.second + nb.second));
            if(vp(nr.second)) nr.first = -d(nr.second, t);
            if(vp(nr.second) && is_valid(nr.second)){
                if(vis.count(nr.second)) continue;
                if(nr.second == t) return true;
                vis.insert(nr.second), Q.push(nr);
            }
        }
    }
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int _; cin>>_;
    while(_--){
        cin>>n>>m>>k>>q;
        for(int i=0;i<=q;i++) cin>>arr[i].first>>arr[i].second;
        cin>>s.first>>s.second>>t.first>>t.second;
        cout<<(solve() ? "Yes" : "No")<<endl;
    }
    return 0;
}
