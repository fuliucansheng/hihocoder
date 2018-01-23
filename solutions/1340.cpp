#include <iostream>
#include <cmath>
using namespace std;
int solve(int x, int y, int z){
    int res = 0;
    if(x <= y + z) res = 6 * ceil((x + y + z) / 20.0);
    else{
        int m = (y + z) % 10, d = (y + z) / 10;
        res += 6 * d;
        x -= 10 * d;
        if(m > 7) x -= m, res += 6;
        else x -= (15 - m), res += 6;
        if(x > 0) res += 6 * ceil(x/15.0);
    }
    return res;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int x,y,z;
    cin>>x>>y>>z;
    int mx = max(x, max(y, z)), mz = min(x, min(y, z)), my = (x + y + z) - mx - mz;
    cout<<solve(mx, my, mz)<<endl;
    return 0;
}
