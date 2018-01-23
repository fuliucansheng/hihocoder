#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define g(n) graph[n.first][n.second]
#define rz(n) rec[n.first][n.second].size()
#define r(n) rec[n.first][n.second]
#define nl(n) n.first > 0 ? node(n.first-1, n.second) : node(-1, -1)
#define nlt(n) n.first > 0 && n.second > 0 ? node(n.first-1, n.second-1) : node(-1, -1)
#define nlb(n) n.first > 0 && n.second < mm-1 ? node(n.first-1, n.second+1) : node(-1, -1)
#define nr(n) n.first < nn-1 ? node(n.first+1, n.second) : node(-1, -1)
#define nrt(n) n.first < nn-1 && n.second > 0 ? node(n.first+1, n.second-1) : node(-1, -1)
#define nrb(n) n.first < nn-1 && n.second < mm-1 ? node(n.first+1, n.second+1) : node(-1, -1)
#define nt(n) n.second > 0 ? node(n.first, n.second-1) : node(-1, -1)
#define nb(n) n.second < mm-1 ? node(n.first, n.second+1) : node(-1, -1)
#define st(n) {nl(n), nlt(n), nlb(n), nr(n), nrt(n), nrb(n), nt(n), nb(n)}
typedef pair<int,int> node;
const int maxn = 205;
int mm, nn, graph[maxn][maxn];
void solve(){
    set<node> m, nm;
    set<node> rec[maxn][maxn], nbr[maxn][maxn];
    for(int i=0;i<nn;i++) for(int j=0;j<mm;j++)
            if(g(node(i,j)) != -1) {
                set<node> tp = st(node(i,j));
                for(auto s:tp) if(s != node(-1,-1) && g(s) == -1) r(node(i,j)).insert(s);
                for(int di=-2;di<3;di++) for(int dj=-2;dj<3;dj++) if(i+di >= 0 && i+di < nn && j+dj >=0 && j+dj < mm && g(node(i+di,j+dj)) != -1) nbr[i][j].insert(node(i+di,j+dj));
                nbr[i][j].erase(node(i,j));
            }
    for(int i=0;i<nn;i++) for(int j=0;j<mm;j++){
            if(g(node(i,j)) == 0) for(auto s:r(node(i,j))) nm.insert(s);
            if(g(node(i,j)) == r(node(i,j)).size()) for(auto s:r(node(i,j))) m.insert(s);
            if(g(node(i,j)) != -1){
                set<node> nrc;
                for(auto b:nbr[i][j]){
                    nrc.clear();
                    node ms = (rz(node(i,j)) >= rz(b) ? node(i,j) : b), ns = (rz(node(i,j)) < rz(b) ? node(i,j) : b);
                    set_union(r(ms).begin(),r(ms).end(),r(ns).begin(),r(ns).end(),inserter(nrc,nrc.end()));
                    if(nrc.size() == rz(ms) && rz(ms)-rz(ns) == g(ms) - g(ns))
                        for(auto s:r(ms)) if(r(ns).find(s) == r(ns).end()) m.insert(s);
                }
            }
        }
    cout<<m.size()<<" "<<nm.size()<<endl;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        cin>>nn>>mm;
        for(int i=0;i<nn;i++) for(int j=0;j<mm;j++) cin>>graph[i][j];
        solve();
    }
    return 0;
}
