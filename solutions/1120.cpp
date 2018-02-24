#include <bits/stdc++.h>
using namespace std;
#define g(p) graph[p.first][p.second]
#define vp(p) (p.first >= 0 && p.first < nn && p.second >= 0 && p.second < mm)
typedef pair<int,int> pii;
const int maxn = 12;
vector<pii> nbr = { pii(-1,-1), pii(-1,0), pii(-1,1), pii(0,-1), pii(0,1), pii(1,-1), pii(1,0), pii(1,1) };
int graph[maxn][maxn], mm, nn;
map<pii,pii> dict;
void upd(pii d, int type){
    set<pii> ss;
    for(auto nb:nbr) {
        pii nr = pii(d.first+nb.first, d.second+nb.second);
        if(vp(nr)) ss.insert(nr);
    }
    if(type == 0) { for(auto s:ss) if(dict[s].second) dict[s].second--; }
    else {
        for(auto s:ss) if(dict[s].first && dict[s].second) dict[s].first--, dict[s].second--;
    }
}
set<pii> get_nbr(pii u){
    set<pii> rs;
    for(auto nb:nbr) {
        pii nr = pii(u.first+nb.first, u.second+nb.second);
        if(vp(nr)) rs.insert(nr);
    }
    return rs;
}
void solve(int &r1, int &r2){
    set<pii> unk;
    for(int i=0;i<nn;i++) for(int j=0;j<mm;j++){
            pii curr = pii(i,j);
            if(g(curr) != -1){
                set<pii> ss = get_nbr(curr);
                dict[pii(i,j)] = pii(g(pii(i,j)), 0);
                for(auto s:ss) if(g(s) == -1) dict[pii(i,j)].second++;
            }else unk.insert(pii(i,j));
        }
    while(true){
        int rec = r1 + r2;
        for(auto d:dict){
            set<pii> ss = get_nbr(d.first);
            if(g(d.first) != -1 && d.second.first == 0){
                for(auto s:ss) if(unk.find(s) != unk.end()) upd(s, 0), r2++, unk.erase(s);
            } else if(g(d.first) != -1 && d.second.first == d.second.second){
                for(auto s:ss) if(unk.find(s) != unk.end()) upd(s, 1), r1++, unk.erase(s);
            }
        }
        if(rec == (r1 + r2)) break;
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        cin>>nn>>mm;
        dict.clear();
        for(int i=0;i<nn;i++) for(int j=0;j<mm;j++) cin>>graph[i][j];
        int r1 = 0, r2 = 0;
        solve(r1, r2);
        cout<<r1<<" "<<r2<<endl;
    }
    return 0;
}
