#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 150;
const ll mod = 1000000007;
ll n, k, mm, md;
void mat_mul(ll A[maxn][maxn], ll B[maxn][maxn], ll C[maxn][maxn]) {
    ll R[maxn][maxn]; memset(R, 0, sizeof(R));
    for(ll i = 0; i < mm; i++) {
        for(ll j = 0; j < mm; j++) for(ll x = 0; x < mm; x++) R[i][j] += A[i][x] * B[x][j], R[i][j] %= mod;
    }
    for(ll i = 0; i < mm; i++) for(ll j = 0; j < mm; j++) C[i][j] = R[i][j];
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>k;
    md = 1 + 2 * k, mm = 1 << md;
    ll M[maxn][maxn];
    memset(M, 0, sizeof(M));
    for(ll i = 1; i < mm; i++) {
        if(i & 1) {
            ll nx = (i >> 1) | (1 << (md - 1));
            M[i][nx]++;
        } else {
            for(ll j = 0; j < md; j++) if(i >> j & 1) {
                ll nx = i ^ (1 << j);
                nx = (nx >> 1)|(1 << md - 1);
                M[i][nx]++;
            }
        }
    }
    ll A[maxn][maxn], nn = n; memset(A, 0, sizeof(A));
    for(ll i = 0; i < mm; i++) A[i][i] = 1;
    while(nn) {
        if(nn & 1) mat_mul(A, M, A);
        mat_mul(M, M, M), nn >>= 1;
    }
    ll s = (1 << (k + 1)) - 1;
    s <<= k;
    ll t = 0;
    for(ll i = k; i < md; i++) t |= (1 << i);
    ll ans = A[s][t];
    cout<<(ans + mod) % mod<<endl;
    return 0;
}
