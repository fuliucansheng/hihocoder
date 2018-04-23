#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 12357, maxsk = 1<<7;
int n, k, sk;
void iter(ll a[][maxsk], ll b[][maxsk], ll c[][maxsk]){
    ll R[sk][sk];memset(R, 0, sizeof(R));
    for(int i=0;i<sk;i++) for(int j=0;j<sk;j++) for(int k=0;k<sk;k++) R[i][j] += a[i][k]*b[k][j];
    for(int i=0;i<sk;i++) for(int j=0;j<sk;j++) c[i][j] = R[i][j]%mod;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>k>>n; sk = 1<<k;
    ll A[sk][maxsk], M[sk][maxsk];
    memset(M, 0, sizeof(M)); memset(A, 0, sizeof(A));
    for(int s = 0; s < sk; s++){
        int ns = ((1<<k)-1) - s; M[s][ns] = 1;
        queue<int> Q; Q.push(ns);
        while(!Q.empty()){
            int f = Q.front();Q.pop();
            for(int i = 1; i < k; i++) {
                if((f&(1<<i)) == 0 && (f&(1<<(i-1))) == 0) M[s][f|(1<<i)|1<<(i-1)] = 1, Q.push(f|(1<<i)|(1<<(i-1)));
            }
        }
    }
    for(int i = 0; i < sk; i++) A[i][i] = 1;
    while(n){
        if(n&1) iter(A, M, A);
        iter(M, M, M);
        n >>= 1;
    }
    cout<<A[sk - 1][sk - 1]<<endl;
    return 0;
}
