#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
using namespace std;
#define g(p) graph[p.first][p.second]
#define v(p) vis[p.first][p.second]
#define vp(p) (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m)
#define ss(p) sds[p.first][p.second]
typedef pair<int,int> ps;
const int maxn = 305;
vector<ps> nbr = {ps(-1,0), ps(1,0), ps(0,-1), ps(0,1)};
int sds[maxn][maxn], dis[15][15], dt = 1, m, n, k;
string graph[maxn];
bool vis[maxn][maxn];
map<ps,int> dict;
void bfs(ps s){
    if(g(s) == '1') return;
    queue<ps> Q;
    memset(vis, 0, sizeof(vis)); memset(sds, -1, sizeof(sds));
    Q.push(s), v(s) = true, ss(s) = 0;
    int ds = 1;
    while(!Q.empty()){
        int qz = Q.size();
        for(int i=0;i<qz;i++){
            ps f = Q.front(); Q.pop();
            for(auto nb:nbr){
                ps nr = ps(f.first+nb.first, f.second+nb.second);
                if(vp(nr) && g(nr) == '0' && !v(nr)) v(nr) = true, ss(nr) = ds, Q.push(nr);
            }
        }
        ds++;
    }
    int sx = dict[s];
    for(auto p:dict) dis[p.second][sx] = dis[sx][p.second] = ss(p.first);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dis, -1, sizeof(dis));
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>graph[i];
    ps s = ps(0, 0), e = ps(n-1, m-1);
    for(int i=0;i<k;i++) {
        int x, y; cin>>x>>y;
        if(dict.find(ps(x,y)) == dict.end()) dict[ps(x,y)] = dt++;
    }
    int kk = dt; kk--;
    if(dict.find(s) == dict.end()) dict[s] = dt++;
    if(dict.find(e) == dict.end()) dict[e] = dt++;
    for(auto p:dict) bfs(p.first);
    int sx = dict[s], ex = dict[e], np[k];
    for(int i=0;i<kk;i++) np[i] = i+1;
    int rs = INT32_MAX;
    if(kk > 0){
        do{
            if(dis[sx][np[0]] == -1 || dis[ex][np[kk-1]] == -1) continue;
            int r = dis[sx][np[0]] + dis[ex][np[kk-1]];
            for(int i=1;i<kk;i++) {
                if(dis[np[i]][np[i-1]] == -1) { r = INT32_MAX; break; }
                r += dis[np[i]][np[i-1]];
            }
            rs = min(rs, r);
        }while(next_permutation(np, np+kk));
    }else rs = dis[sx][ex] == -1 ? INT32_MAX : dis[sx][ex];
    cout<<(rs == INT32_MAX ? -1 : rs)<<endl;
    return 0;
}
