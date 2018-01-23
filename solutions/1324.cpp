#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll dfs(ll n, ll x, ll y){
    if(n == 1){
        if(x == 1 && y == 1) return 1;
        if(x == 1 && y == 2) return 2;
        if(x == 2 && y == 2) return 3;
        return 4;
    }
    ll cnt, nx, ny, rs, s = pow(4, n-1), ds = pow(2, n-1);
    if(x <= ds && y <= ds) {
        cnt = 0, nx = x, ny = y;
        ll nnx = ds - ny + 1, nny = nx;
        rs = dfs(n-1, nnx, nny);
        return cnt + s - rs + 1;
    }
    else if(x <= ds && y > ds) cnt = s, nx = x, ny = y - ds;
    else if(x > ds && y > ds) cnt = 2*s, nx = x - ds, ny = y - ds;
    else {
        cnt = 3*s, nx = x - ds, ny = y;
        ll nnx = ny, nny = ds - nx + 1;
        rs = dfs(n-1, nnx, nny);
        return cnt + s - rs + 1;
    }
    rs = dfs(n-1, nx, ny);
    return cnt + rs;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    long long n, x, y; cin>>n>>x>>y;
    cout<<dfs(n, x, y)<<endl;
    return 0;
}
