#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
void mmul(ll A[2][2], ll B[2][2], ll C[2][2]){
    ll R[2][2] = {0};
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) R[i][j] += A[i][k] * B[k][j], R[i][j] %= mod;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) C[i][j] = R[i][j];
}
void mpow(ll n, ll M[2][2], ll R[2][2]){
    ll C[2][2] = {1, 0, 0, 1}, A[2][2];
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) A[i][j] = M[i][j] % mod;
    while(n){
        if(n&1) mmul(A, C, C);
        mmul(A, A, A);
        n >>= 1;
    }
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) R[i][j] = C[i][j];
}
ll extend_gcd(ll a, ll b, ll& x, ll& y){
    if(b == 0) return x = 1, y = 0, a;
    ll d = extend_gcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
int main() {
    //freopen("../input.txt", "r" , stdin);
    ll k1, k2, x, y, Ax, Ay, z; cin>>k1>>k2>>x>>y>>Ax>>Ay>>z;
    ll M[2][2] = {k1, k2, 1, 0}, Mx[2][2], My[2][2], Mz[2][2];
    ll px = x - 2, py = y - 2, pz = z - 2;
    mpow(px, M, Mx); mpow(py, M, My); mpow(pz, M, Mz);
    ll k1x = Mx[0][0], k2x = Mx[0][1], k1y = My[0][0], k2y = My[0][1], k1z = Mz[0][0], k2z = Mz[0][1];
    ll cm = ((k1x * k2y - k1y * k2x) % mod + mod) % mod;
    ll a1 = ((k1x * Ay - k1y * Ax) % mod + mod) % mod, a2 = ((k2y * Ax - k2x * Ay) % mod + mod) % mod;
    ll cc, _; extend_gcd(cm, mod, cc, _);
    a1 = a1 * cc % mod, a2 = a2 * cc % mod;
    ll Az = ((k1z * a2 + k2z * a1) % mod + mod) % mod;
    cout<<Az<<endl;
    return 0;
}
