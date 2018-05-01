#include <bits/stdc++.h>
using namespace std;
#define v(p) vs[p.first][p.second.first][p.second.second]
#define a(p) arr[p.first][p.second]
#define vp(p) (p.first >= 0 && p.first < n && p.second >= 0 && p.second < n)
typedef pair<int,int> pii;
typedef pair<bool,pii> pbi;
const int maxn = 1010;
vector<pii> nbr = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
string arr[maxn];
bool vs[2][maxn][maxn];
int n;
int bfs() {
    memset(vs, 0, sizeof(vs));
    queue<pbi> Q;
    pbi s = { 1, { 0, 0 } };
    if(a(pii(0,0)) == '#') s.first = 0;
    Q.push(s), v(s) = true;
    int ret = 0;
    while(!Q.empty()) {
        int qz = int(Q.size());
        for(int i = 0; i < qz; i++) {
            auto f = Q.front(); Q.pop();
            if(f.second == pii(n - 1, n - 1)) return ret;
            for(auto nb : nbr) {
                pii nr = { f.second.first + nb.first, f.second.second + nb.second };
                if(vp(nr)) {
                    if(a(nr) == '.' && !v(pbi(f.first, nr))) Q.push(pbi(f.first, nr)), v(pbi(f.first, nr)) = true;
                    if(a(nr) == '#' && f.first == 1 && !v(pbi(0, nr))) Q.push(pbi(0, nr)), v(pbi(0, nr)) = true;
                }
            }
        }
        ret++;
    }
    return -1;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    cout<<bfs()<<endl;
    return 0;
}
