#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define v(p) vis[p.first.first][p.first.second][p.second]
#define a(p) arr[p.first.first][p.first.second][p.second]
#define vp(p) (p.first.first > 0 && p.first.first <= n && p.first.second > 0 && p.first.second <= m && p.second > 0 && p.second < 5)
typedef pair<pair<int,int>,int> ps;
const int maxn = 105;
int arr[maxn][maxn][5], vis[maxn][maxn][5], m, n;
vector<ps> get_nbr(ps p){
    vector<ps> rs;
    if(p.second == 1 && vp(ps(make_pair(p.first.first, p.first.second-1),3))) rs.push_back(ps(make_pair(p.first.first, p.first.second-1),3));
    if(p.second == 2 && vp(ps(make_pair(p.first.first+1, p.first.second),4))) rs.push_back(ps(make_pair(p.first.first+1, p.first.second),4));
    if(p.second == 3 && vp(ps(make_pair(p.first.first, p.first.second+1),1))) rs.push_back(ps(make_pair(p.first.first, p.first.second+1),1));
    if(p.second == 4 && vp(ps(make_pair(p.first.first-1, p.first.second),2))) rs.push_back(ps(make_pair(p.first.first-1, p.first.second),2));
    ps np = ps(p.first, (p.second+1 == 5 ? 1 : p.second+1)), pp = ps(p.first, (p.second-1 == 0 ? 4 : p.second-1));
    if(a(p) == a(np)) rs.push_back(np);
    if(a(p) == a(pp)) rs.push_back(pp);
    return rs;
}
void dfs(ps ne){
    queue<ps> Q; Q.push(ne);
    v(ne) = 1;
    while(!Q.empty()){
        ps f = Q.front(); Q.pop();
        vector<ps> r = get_nbr(f);
        for(auto rr:r) if(!v(rr)) v(rr) = 1, Q.push(rr);
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(vis, 0, sizeof(vis));
    cin>>n>>m; cin.get();
    for(int i=1;i<=n;i++) {
        char s[maxn]; cin.getline(s, maxn);
        for(int j=1;j<=m;j++){
            char ch = s[j-1];
            if(ch == '/') arr[i][j][1] = arr[i][j][4] = i, arr[i][j][2] = arr[i][j][3] = i * -1;
            else if(ch == '\\') arr[i][j][1] = arr[i][j][2] = i, arr[i][j][3] = arr[i][j][4] = i * -1;
            else arr[i][j][1] = arr[i][j][2] = arr[i][j][3] = arr[i][j][4] = i;
        }
    }
    int rs = 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=1;k<5;k++) if(!v(ps(make_pair(i,j),k))) dfs(ps(make_pair(i,j),k)), rs++;
    cout<<rs<<endl;
    return 0;
}
