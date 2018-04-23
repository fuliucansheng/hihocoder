#include <bits/stdc++.h>
using namespace std;
const int mod = 12357;
int M[8][8], A[8][8];
void iter(int a[8][8], int b[8][8], int c[8][8]){
    int R[8][8]; memset(R, 0, sizeof(R));
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            R[i][j] = 0;
            for(int k = 0; k < 8; k++) R[i][j] += a[i][k]*b[k][j];
        }
    for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) c[i][j] = R[i][j]%mod;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    for(int i = 0; i < 8; i++) A[i][i] = M[i][7-i] = 1;
    M[3][7] = M[6][7] = M[7][3] = M[7][6] = 1;
    int n; cin>>n;
    while(n){
        if(n&1) iter(A, M, A);
        iter(M, M, M);
        n >>= 1;
    }
    cout<<A[7][7]<<endl;
    return 0;
}
