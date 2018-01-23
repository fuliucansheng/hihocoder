#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define d(s) dp[s.first.first][s.first.second][s.second]
#define r(p) rec[p.first][p.second]
#define a(p) arr[p.first][p.second]
#define pv(p) (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m)
const int maxn = 101;
typedef pair<int,int> ps;
typedef pair<ps,int> st;
vector<ps> nbr = {ps(-1,0), ps(1,0), ps(0,-1), ps(0,1)};
int dp[maxn][maxn][32], rec[maxn][maxn];
string arr[maxn];
int m, n;
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp)); memset(rec, 0, sizeof(rec));
    int k, a, b, c, d, x, y, rs = INT32_MAX, ds = 0;
    cin>>n>>m>>k>>a>>b>>c>>d;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<k;i++) cin>>x>>y, rec[x][y] |= (1<<i);
    st s = st(ps(a,b), 0);
    queue<st> Q;
    Q.push(s), d(s) = 0;
    while(!Q.empty()){
        int qz = Q.size();
        while(qz--){
            st f = Q.front(); Q.pop();
            for(auto nb:nbr){
                ps nr = ps(f.first.first + nb.first, f.first.second + nb.second);
                int state = f.second | r(f.first);
                st snr = st(nr, state);
                if(pv(nr) && d(snr) == -1 && a(nr) != '#'){
                    if(a(nr) == '.' || ((1<<(a(nr) - 'A'))&f.second)) Q.push(snr), d(snr) = ds + 1;
                }
            }
        }
        ds++;
    }
    for(int i=0;i<32;i++) if(dp[c][d][i] != -1) rs = min(rs, dp[c][d][i]);
    cout<<(rs == INT32_MAX ? -1 : rs)<<endl;
    return 0;
}
