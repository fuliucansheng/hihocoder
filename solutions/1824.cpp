#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("../input.txt", "r", stdin);
    int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    int dx = x2 - x1, dy = y2 - y1;
    int rx = x2, ry = y2;
    if(dx == 0 || dy == 0) {
        if(dx == 0) rx += (y2 > y1 ? 1 : -1);
        if(dy == 0) ry += (x2 > x1 ? -1 : 1);
        cout<<rx<<" "<<ry<<endl;
        return 0;
    }
    swap(dx, dy), dx *= -1;
    if(dx < 0) dy *= -1, dx *= -1;
    int d = __gcd(dx, abs(dy));
    dx /= d, dy /= d;
    if(x2 > x1) {
        if(y2 > y1) rx += dx, ry += dy;
        else rx -= dx, ry -= dy;
    } else {
        if(y2 > y1) rx += dx, ry += dy;
        else rx -= dx, ry -= dy;
    }
    cout<<rx<<" "<<ry<<endl;
    return 0;
}
