#include <iostream>
#include <cmath>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    double x, y, r; cin>>x>>y>>r;
    int xl = int(ceil(x - r)), xr = int(floor(x + r));
    double ms = -1, mx, my;
    for(int xx=xl;xx<=xr;xx++){
        int yt = int(floor(y + sqrt(r*r-(xx-x)*(xx-x)))), yb = int(ceil(y - sqrt(r*r-(xx-x)*(xx-x))));
        double dyt = sqrt((yt-y)*(yt-y)+(xx-x)*(xx-x)), dyb = sqrt((yb-y)*(yb-y)+(xx-x)*(xx-x));
        if(dyt >= dyb && dyt >= ms) ms = dyt, mx = xx, my = yt;
        if(dyb > dyt && dyb >= ms) ms = dyb, mx = xx, my = yb;
    }
    cout<<mx<<" "<<my<<endl;
    return 0;
}
