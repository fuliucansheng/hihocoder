#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define v(s) vis[s.first][s.second]
#define a(s) arr[s.first][s.second]
#define r(s) rec[s.first][s.second]
#define vd(s) (s.first >= 0 && s.first < n && s.second >= 0 && s.second < m)
typedef pair<int,int> ps;
const int maxn = 101;
vector<ps> nbr = {ps(0,1), ps(0,-1), ps(-1,0), ps(1,0)};
int arr[maxn][maxn], rec[maxn][maxn], vis[maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int m, n, x, y; cin>>n>>m>>x>>y;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    memset(rec, 0, sizeof(rec));memset(vis, 0, sizeof(vis));
    queue<ps> Q;Q.push(ps(x,y));
    vis[x][y] = 1;
    while(!Q.empty()){
        ps f = Q.front(); Q.pop();
        for(auto nb:nbr){
            ps b = ps(f.first+nb.first, f.second+nb.second);
            if(vd(b) && a(f) == a(b)) r(f)++;
            if(vd(b) && a(f) == a(b) && !v(b)) Q.push(b), v(b) = 1;
        }
    }
    int c = 0, s = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) c += (rec[i][j] != 0), s += rec[i][j];
    cout<<(4*c-s > 0 ? 4*c-s : 4)<<endl;
    return 0;
}
