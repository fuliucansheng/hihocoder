#include <bits/stdc++.h>

using namespace std;
const int maxn = 30;
const double eps = 1e-6;
typedef double Matrix[maxn][maxn];

void gauss_elimination(Matrix A, int m, int n) {
    int i, j, k, r;
    for (i = 0; i < n; i++) {
        r = i;
        for (j = i + 1; j < m; j++) if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        if (r != i) for (j = 0; j <= n; j++) swap(A[r][j], A[i][j]);
        for (j = n; j >= i; j--) for (k = i + 1; k < m; k++) A[k][j] -= A[k][i] / A[i][i] * A[i][j];
    }
    for (i = n - 1; i >= 0; i--) {
        for (j = i + 1; j < n; j++) A[i][n] -= A[j][n] * A[i][j];
        A[i][n] /= A[i][i];
    }
}

int main() {
    //freopen("../input.txt", "r", stdin);
    int n, c = 0;
    cin >> n;
    int a[n + 2] = {0}, p = (n + 1) / 2 + 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n + 1; i++) c += (a[i] != a[i - 1]);
    Matrix dp = { 0 }; dp[0][0] = 1.0;
    for (int i = 2; i <= n + 1; i += 2){
        dp[i / 2][i / 2] = 1.0;
        dp[i / 2][i / 2 - 1] -= 1.0 * i * (i - 1) / n / (n + 1);
        dp[i / 2][i / 2] -= 2.0 * i * (n + 1 - i) / n / (n + 1);
        dp[i / 2][i / 2 + 1] -= 1.0 * (n + 1 - i) * (n - i) / n / (n + 1);
        dp[i / 2][p] = 1.0;
    }
    gauss_elimination(dp, p, p);
    cout<<fixed<<setprecision(10)<<dp[c / 2][p]<<endl;
    return 0;
}
