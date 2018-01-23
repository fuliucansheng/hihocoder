#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> ps;
#define dx(p) (p.first * 1000 + p.second)
#define g(p) graph[p.first][p.second]
#define vp(p) (p.first >= 0 && p.first < 1000 && p.second >= 0 && p.second < 1000)
const int maxn = 1000;
vector<ps> nbr = { ps(-1,0), ps(1,0), ps(0,1), ps(0,-1) };
int group[maxn*maxn], graph[maxn][maxn];
int find_group(int x){
    return x == group[x] ? x : find_group(group[x]);
}
void union_group(int x, int y){
    int gx = find_group(x), gy = find_group(y);
    group[gx] = group[gy] = min(gx, gy);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(graph, 0, sizeof(graph));
    for(int i=0;i<maxn*maxn;i++) group[i] = i;
    int n, c = 0, e = 0, l = 0, cl = 0; cin>>n;
    ps p;
    for(int i=0;i<n;i++){
        cin>>p.first>>p.second;
        g(p) = 1, cl = 4;
        for(auto nb:nbr){
            ps nr = ps(p.first+nb.first, p.second+nb.second);
            if(vp(nr) && g(nr) == 1) {
                int dxp = find_group(dx(p)), dxr = find_group(dx(nr));
                if(dxp != dxr) union_group(dxp, dxr), c--;
                l--, cl--;
            }
        }
        c++, e++, l += cl;
        cout<<c<<" "<<e<<" "<<l<<endl;
    }
    return 0;
}
