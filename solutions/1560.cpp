#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef ll vec[10];
typedef ll mat[10][10];
const ll mod = 1000000007;
void xmat(mat a, mat b, mat c){
    mat r;
    for(ll i=0;i<10;i++) for(ll j=0;j<10;j++) r[i][j] = 0;
    for(ll i=0;i<10;i++) for(ll j=0;j<10;j++) for(ll k=0;k<10;k++) r[i][j] += a[i][k] * b[k][j], r[i][j] %= mod;
    for(ll i=0;i<10;i++) for(ll j=0;j<10;j++) c[i][j] = r[i][j];
}
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    ll n, k, rs = 0; cin>>n>>k;
    vec x, ans;
    for(ll i=0;i<10;i++) x[i] = (i > 0 && i <= k);
    mat m, r;
    for(ll i=0;i<10;i++) ans[i] = 0;
    for(ll i=0;i<10;i++) for(ll j=0;j<10;j++) m[i][j] = (i <= k && (i * j) <= k);
    for(ll i=0;i<10;i++) for(ll j=0;j<10;j++) r[i][j] = (i == j);
    ll p = n - 1;
    while(p){
        if(p&1) xmat(m, r, r);
        xmat(m, m, m), p >>= 1;
    }
    for(ll i=0;i<10;i++) for(ll j=0;j<10;j++) ans[i] += (r[i][j] * x[j] % mod), ans[i] %= mod;
    for(ll i=0;i<10;i++) rs += ans[i], rs %= mod;
    if(n == 1) rs++;
    cout<<(rs + mod) % mod<<endl;
    return 0;
}
