#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("../input.txt","r",stdin);
    int x, y, z, ans = 0, rr = 0, yy = 0, bb = 0, cnt = 0;
    cin>>x>>y>>z;
    int mx = max({x, y, z}), mz = min({x, y, z}), my = (x + y + z) - mx - mz;
    string s;
    cin>>s;
    for(int i=0;i<int(s.size());i++){
        if(s[i] == 'R') rr++;
        else if(s[i] == 'Y') yy++;
        else bb++;
        cnt++;
        int ry = abs(rr - yy), yb = abs(yy - bb), rb = abs(rr - bb);
        int mmx = max({ry, yb, rb}), mmz = min({ry, yb, rb}), mmy = (ry + yb + rb) - mmx - mmz;
        if(mmx == mx && mmy == my && mmz == mz) ans = max(ans, cnt), rr = yy = bb = cnt = 0;
    }
    cout<<max(ans, cnt)<<endl;
    return 0;
}
