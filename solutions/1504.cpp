#include <bits/stdc++.h>
using namespace std;
#define vp(p) (p.first >= 0 && p.first < 8 && p.second >= 0 && p.second < 8)
#define xp(p) p.first * 8 + p.second
typedef long long ll;
typedef pair<int,int> pii;
typedef ll Matrix[64][64];
typedef ll Vector[64];
const ll mod = 1000000007;
vector<pii> nbr = { pii(-2,-1), pii(-2,1), pii(2,-1), pii(2,1), pii(-1,-2), pii(-1,2), pii(1,-2), pii(1,2) };
void mat_mul(Matrix A, Matrix B, Matrix C){
    Matrix R;
    for(int i=0;i<64;i++) for(int j=0;j<64;j++) R[i][j] = 0;
    for(int i=0;i<64;i++) for(int j=0;j<64;j++) for(int k=0;k<64;k++) R[i][j] += A[i][k] * B[k][j], R[i][j] %= mod;
    for(int i=0;i<64;i++) for(int j=0;j<64;j++) C[i][j] = R[i][j];
}
void mat_vec_mul(Matrix A, Vector B, Vector C){
    Vector R;
    for(int i=0;i<64;i++) R[i] = 0;
    for(int i=0;i<64;i++) for(int k=0;k<64;k++) R[i] += A[i][k] * B[k], R[i] %= mod;
    for(int i=0;i<64;i++) C[i] = R[i];
}
void mat_pow_mod(Matrix M, int x, Vector A){
    while(x){
        if(x&1) mat_vec_mul(M, A, A);
        x>>=1; mat_mul(M, M, M);
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n, r, c; cin>>n>>r>>c;
    Matrix M;
    for(int i=0;i<64;i++) for(int j=0;j<64;j++) M[i][j] = 0;
    Vector A;
    for(int i=0;i<64;i++) A[i] = 0;
    A[xp(pii(r-1,c-1))] = 1;
    for(int i=0;i<8;i++) for(int j=0;j<8;j++){
            for(auto nb:nbr){
                pii nr = pii(i+nb.first,j+nb.second);
                if(vp(nr)) M[xp(nr)][xp(pii(i,j))] = 1;
            }
        }
    mat_pow_mod(M, n, A);
    ll ans = 0;
    for(int i=0;i<64;i++) ans += A[i], ans %= mod;
    cout<<(ans + mod) % mod<<endl;
    return 0;
}
