#include <bits/stdc++.h>
using namespace std;
#define d(a, b) sqrt(double(a.first - b.first) * double(a.first - b.first) + double(a.second - b.second) * double(a.second - b.second))
typedef pair<int,int> pii;
const int maxn = 105;
pii pnt[maxn];
int m, n;
double dp[maxn][maxn][maxn], rc[maxn][maxn][maxn];
double garea(int a, int b, int c){
    double dab = d(pnt[a], pnt[b]), dac = d(pnt[a], pnt[c]), dbc = d(pnt[b], pnt[c]);
    double s = (dab + dac + dbc) / 2;
    return sqrt(s*(s-dab)*(s-dac)*(s-dbc));
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>pnt[i].first>>pnt[i].second;
    memset(dp, 0, sizeof(dp)); memset(rc, 0, sizeof(rc));
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) rc[i][j][k] = garea(i,j,k);
    for(int i=0;i<n;i++) for(int j=i+2;j<n;j++) for(int k=1;k<m;k++){
                for(int a=i+1;a<j;a++) dp[i][j][k] = max(dp[i][j][k], dp[i][a][k-1] + rc[i][a][j]);
            }
    double ans = 0;
    for(int i=0;i<n;i++) for(int j=i+2;j<n;j++) ans = max(ans, dp[i][j][m-2]);
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}
