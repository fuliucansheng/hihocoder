#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef ll vec[4];
typedef ll mat[4][4];
const ll mod = 1000000007;
void xmat(mat a, mat b, mat c){
    mat r;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) r[i][j] = 0;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<4;k++) r[i][j] += a[i][k] * b[k][j], r[i][j] %= mod;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) c[i][j] = r[i][j];
}
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    int t; cin>>t;
    while(t--){
        ll n, a, b, c, d; cin>>n>>a>>b>>c>>d;
        vec x = { 4, -a, (a * a % mod - 2 * b) % mod, (-a * ((a * a % mod - 2 * b) % mod) + (b * a) % mod - 3 * c) % mod };
        mat m = { { -a, -b, -c, -d }, { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 } };
        if(n < 4) { cout<<x[n]<<endl; continue; }
        ll p = n - 3;
        mat r;
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) r[i][j] = (i == j);
        while(p){
            if(p&1) xmat(m, r, r);
            xmat(m, m, m), p >>= 1;
        }
        ll ans = 0;
        for(int i=0;i<4;i++) ans += (r[0][i] * x[3 - i] % mod), ans %= mod;
        cout<<(ans + mod) % mod<<endl;
    }
    return 0;
}
