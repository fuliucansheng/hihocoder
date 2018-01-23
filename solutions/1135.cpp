#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    //freopen("../input.txt","r",stdin);
    int x, y, z, res = 0, rr = 0, yy = 0, bb = 0, count = 0;
    cin>>x>>y>>z;
    int mx = max(x, max(y,z)), mz = min(x, min(y,z)), my = (x+y+z)-mx-mz;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'R') rr++;
        else if(s[i] == 'Y') yy++;
        else bb++;
        count++;
        int ry = abs(rr - yy), yb = abs(yy - bb), rb = abs(rr - bb);
        int mmx = max(ry, max(yb, rb)), mmz = min(ry, min(yb, rb)), mmy = (ry + yb + rb) - mmx - mmz;
        if(mmx == mx && mmy == my && mmz == mz) res = max(res, count), rr = yy = bb = count = 0;
    }
    cout<<max(res,count)<<endl;
    return 0;
}
