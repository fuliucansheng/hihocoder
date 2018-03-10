#include <bits/stdc++.h>
using namespace std;
#define vp(p) (p.first < n && p.first >= 0 && p.second < n && p.second >= 0)
#define ds(p) d[p.first][p.second]
typedef pair<int,int> pii;
typedef pair<int,pii> ppi;
const int maxn = 1010;
int d[maxn][maxn];
vector<pii> nbr = { pii(-1,0), pii(1,0), pii(0,-1), pii(0,1) };
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    memset(d, 0, sizeof(d));
    int n, k; cin>>n>>k;
    priority_queue<ppi> Q;
    for(int i=0;i<k;i++){
        int x, y, g; cin>>x>>y>>g;
        Q.push(ppi(g, pii(x,y)));
        ds(pii(x,y)) = max(g, ds(pii(x,y)));
    }
    while(!Q.empty()){
        ppi f = Q.top(); Q.pop();
        auto p = f.second;
        for(auto nb:nbr){
            pii nr = pii(p.first + nb.first, p.second + nb.second);
            if(vp(nr) && ds(nr) < f.first - 1)  ds(nr) = f.first - 1, Q.push(ppi(f.first - 1, nr));
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<d[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
