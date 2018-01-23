#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define a(s) arr[s.first][s.second]
#define v(s) vis[s.first][s.second]
#define vd(s) (s.first >= 0 && s.first < N && s.second >= 0 && s.second < N)
typedef pair<int,int> ps;
const int N = 8;
int da[N][N], db[N][N], dc[N][N];
vector<ps> nbr = {ps(2,1), ps(2,-1), ps(1,2), ps(1,-2), ps(-2,1), ps(-2,-1), ps(-1,2), ps(-1,-2)};
void bfs(ps s, int arr[N][N]){
    bool vis[N][N];memset(vis, 0, sizeof(vis));
    queue<ps> Q;Q.push(s);v(s) = true;a(s) = 0;
    int ds = 1;
    while(!Q.empty()){
        int qz = Q.size();
        while(qz--){
            ps f = Q.front();Q.pop();
            for(auto nb:nbr){
                ps b = ps(f.first+nb.first, f.second+nb.second);
                if(vd(b) && !v(b)) Q.push(b), v(b) = true, a(b) = ds;
            }
        }
        ds++;
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        string a, b, c; cin>>a>>b>>c;
        ps pa = ps(a[0]-'A', a[1]-'1'), pb = ps(b[0]-'A', b[1]-'1'), pc = ps(c[0]-'A', c[1]-'1');
        bfs(pa, da); bfs(pb, db); bfs(pc, dc);
        int rs = INT32_MAX;
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) rs = min(rs, da[i][j] + db[i][j] + dc[i][j]);
        cout<<rs<<endl;
    }
    return 0;
}
