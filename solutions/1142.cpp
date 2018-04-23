#include <bits/stdc++.h>
using namespace std;
#define yy(x0) (a*x0*x0+b*x0+c)
#define ds(x0,y0,x1,y1) (sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1)))
#define dd(x0) ds(x0,yy(x0),x,y)
double a, b, c, x, y;
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>a>>b>>c>>x>>y;
    double l = -200, r = 200;
    while(true){
        double m1 = l + (r-l)/3, m2 = l + 2*(r-l)/3;
        if(dd(m1) < dd(m2)) r = m2; else l = m1;
        if(ds(r, yy(r), l, yy(l)) < 0.00001) break;
    }
    cout<<fixed<<setprecision(3)<<dd(l)<<endl;
    return 0;
}
