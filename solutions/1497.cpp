#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 100010;
int r[maxn], c[maxn], d[maxn<<1], e[maxn<<1], rc = 1, cc = 1, dc = 1, ec = 1, n, x, y;
map<int,int> rd, cd, dd, ed;
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(r, 0, sizeof(r)); memset(c, 0, sizeof(c)); memset(d, 0, sizeof(d));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(!rd[x]) rd[x] = rc++;
        if(!cd[y]) cd[y] = cc++;
        if(!dd[x+y]) dd[x+y] = dc++;
        if(!ed[x-y]) ed[x-y] = ec++;
        int dx = rd[x], dy = cd[y], dxpy = dd[x+y], dxsy = ed[x-y];
        r[dx]++, c[dy]++, d[dxpy]++, e[dxsy]++;
    }
    int rs = 0;
    for(int i=1;i<maxn;i++) rs += r[i]*(r[i]-1) + c[i]*(c[i]-1);
    for(int i=1;i<(maxn<<1);i++) rs += d[i]*(d[i]-1) + e[i]*(e[i]-1);
    cout<<rs/2<<endl;
    return 0;
}
