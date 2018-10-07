#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 25, mod = 1000000009;
ll a[maxn], k[maxn], M[maxn][maxn], n, m, c;
void iter(ll A[maxn][maxn], ll B[maxn][maxn], ll C[maxn][maxn]) {
    ll ret[maxn][maxn]; memset(ret, 0, sizeof(ret));
    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) for(ll k = 0; k < n; k++) ret[i][j] += A[i][k] * B[k][j], ret[i][j] %= mod;
    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) C[i][j] = ret[i][j];
}
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m>>c;
    for(ll i = 0; i < n; i++) cin>>a[i];
    for(ll i = 0; i < c; i++) cin>>k[i];
    if(m <= n) return cout<<a[m - 1]<<endl, 0;
    m -= n;
    for(ll i = 0; i < n - 1; i++) M[i + 1][i] = 1;
    reverse(a, a + n);
    for(ll i = 0; i < c; i++) M[0][k[i] - 1]++;
    ll A[maxn][maxn]; memset(A, 0, sizeof(A));
    for(ll i = 0; i < n; i++) A[i][i] = 1;
    while(m) {
        if(m & 1) iter(M, A, A);
        m >>= 1, iter(M, M, M);
    }
    ll ret = 0;
    for(ll i = 0; i < n; i++) ret += A[0][i] * a[i], ret %= mod;
    cout<<ret<<endl;
    return 0;
}
