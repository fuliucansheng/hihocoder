#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
#define simpson(a,b,ya,yb,yc) ((ya+4*yc+yb)*(b-a)/6)
typedef long double ld;
const int maxn = 105;
const ld eps = 1e-12;
class node{
public:
    ld l, r, x, y;
    bool operator <(node ne){
        return l < ne.l;
    }
    ld cross(ld nx){
        if(nx <= l || nx >= r) return 0;
        return nx < x ? y*(nx-l)/(x-l) : y*(r-nx)/(r-x);
    }
} ne[maxn];
int n;
ld F(int nl, int nr, ld x){
    ld c = 0;
    for(int i=nl;i<nr;i++) c = max(c, ne[i].cross(x));
    return c;
}
ld asr(int nl, int nr, double a, double b, double ya, double yb, double yab, double p){
    ld c = (b+a)/2, yc = yab;
    ld ac = (a+c)/2, yac = F(nl,nr,ac), bc = (b+c)/2, ybc = F(nl,nr,bc);
    ld l = simpson(a, c, ya, yc, yac), r = simpson(c, b, yc, yb, ybc);
    if(fabs(l+r-p) < eps) return l+r;
    return asr(nl, nr, a, c, ya, yc, yac, l) + asr(nl, nr, c, b, yc, yb, ybc, r);
}

ld asr(int nl, int nr, ld a, ld b){
    ld ya = 0, yb = 0, yab = F(nl, nr, (a+b)/2);
    return asr(nl, nr, a, b, ya, yb, yab, yab*(b-a)*2/3);
}

int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>ne[i].l>>ne[i].r>>ne[i].x>>ne[i].y;
    sort(ne, ne+n);
    int p = 0;
    ld rs = 0, l = ne[p].l, r = ne[p].r;
    for(int i=1;i<n;i++){
        if(ne[i].l >= r){
            rs += asr(p, i, l, r);
            p = i, l = ne[p].l, r = ne[p].r;
        }
        r = max(r, ne[i].r);
    }
    rs += asr(p, n, l, r);
    cout<<fixed<<setprecision(2)<<rs<<endl;
    return 0;
}
