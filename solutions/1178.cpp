#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e7+10;
bool vis[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(vis, 0, sizeof(vis));
    int n, l, r, xr = 1; cin>>n>>l>>r;
    while(xr <= r) xr <<= 1;
    for(int x=0;n*x<=xr;x++){
        int rs = (x^(n*x));
        if(rs >= l && rs <= r) vis[rs] = 1;
    }
    int c = 0;
    for(int i=l;i<=r;i++) c += vis[i];
    cout<<c<<endl;
    return 0;
}
