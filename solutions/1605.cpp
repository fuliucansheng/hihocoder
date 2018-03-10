#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef ll vec[2];
typedef ll mat[2][2];
const ll mod = 1000000007;
void xmat(mat a, mat b, mat c){
    mat r;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) r[i][j] = 0;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) r[i][j] += a[i][k] * b[k][j], r[i][j] %= mod;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) c[i][j] = r[i][j];
}
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    ll n;
    while(cin>>n){
        vec x = { 1, 1 };
        mat m = { { 2, 1 }, { 1, 1 } }, r;
        for(ll i=0;i<2;i++) for(ll j=0;j<2;j++) r[i][j] = (i == j);
        ll p = n - 1;
        while(p){
            if(p&1) xmat(m, r, r);
            xmat(m, m, m), p >>= 1;
        }
        ll ans = (r[0][0] * x[0] + r[0][1] * x[1]) % mod;
        cout<<(ans + mod) % mod<<endl;
    }
    return 0;
}
