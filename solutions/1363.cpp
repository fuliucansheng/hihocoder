#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 4000;
const double eps = 1e-6;
typedef double Matrix[maxn][maxn];
void gauss_elimination(Matrix A, int m, int n){
    int i, j, k, r;
    for(i=0;i<n;i++){
        r = i;
        for(j=i+1;j<m;j++) if(fabs(A[j][i]) > fabs(A[r][i])) r = j;
        if(r!=i) for(j=0;j<=n;j++) swap(A[r][j], A[i][j]);
        for(k=i+1;k<m;k++){
            double f = A[k][i]/A[i][i];
            for(j=i;j<=n;j++) A[k][j] -= f*A[i][j];
        }
    }
    for(i=n-1;i>=0;i--){
        for(j=i+1;j<n;j++) A[i][n] -= A[j][n]*A[i][j];
        A[i][n] /= A[i][i];
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    Matrix A, M;
    int h, w, d; cin>>h>>w>>d;
    int hb = h-d+1, wb = w-d+1;
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) cin>>A[i][j];
    int m = 0, n = d*d;
    for(int i=1;i<=hb;i++) for(int j=1;j<=wb;j++) {
            for(int x=0;x<d;x++) for(int y=0;y<d;y++) M[m][x*d+y] = A[i+x][j+y];
            cin>>M[m++][n];
        }
    gauss_elimination(M, m, n);
    for(int i=0;i<n;i++) {
        if(M[i][n] > -1*eps) cout<<int(M[i][n]+eps)<<" ";
        else cout<<int(M[i][n]-eps)<<" ";
        if(i % d == d - 1) cout<<endl;
    }
    return 0;
}
