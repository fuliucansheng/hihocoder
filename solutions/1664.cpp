#include <iostream>
using namespace std;
const int maxn = 1010;
string arr[maxn];
int r[maxn][maxn], c[maxn][maxn], dp[maxn][maxn], m, n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            r[i][j] = ((j > 0 && arr[i][j] != arr[i][j-1]) ? r[i][j-1] + 1 : 1);
            c[i][j] = ((i > 0 && arr[i][j] != arr[i-1][j]) ? c[i-1][j] + 1 : 1);
        }
    int rs = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(i == 0 || j == 0 || arr[i][j] != arr[i-1][j-1]) dp[i][j] = 1;
            else if(r[i][j] > dp[i-1][j-1] && c[i][j] > dp[i-1][j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = min(r[i][j], c[i][j]);
            rs = max(rs, dp[i][j]);
        }
    cout<<rs<<endl;
    return 0;
}
