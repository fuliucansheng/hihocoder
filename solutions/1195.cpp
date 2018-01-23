#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 505, maxm = 1010;
double arr[maxm][maxn], eps = 1e-6;
int m, n;
void iter(int i, int j, double dx){
    for(int a=0;a<n+1;a++) {
        arr[j][a] += dx*arr[i][a];
        if(fabs(arr[j][a]) < eps) arr[j][a] = 0;
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++) for(int j=0;j<n+1;j++) cin>>arr[i][j];
    int r = 0, c = 0;
    while(c <= n){
        int i = r+1;
        if(arr[r][c] == 0) for(i;i<m;i++) if(arr[i][c]) { iter(i, r, 1); break; }
        if(arr[r][c]) {
            for(i;i<m;i++) iter(r,i,-1*arr[i][c]/arr[r][c]);
            r++;
        }
        c++;
    }
    double rs[n];
    bool ms = false;
    if(arr[n][n] != 0) return cout<<"No solutions"<<endl, 0;
    for(int i=n-1;i>=0;i--){
        double w = arr[i][i], b = arr[i][n];
        for(int j=i+1;j<n;j++) b -= rs[j]*arr[i][j];
        if(b != 0 && w == 0) return cout<<"No solutions"<<endl, 0;
        else if(b == 0 && w == 0) rs[i] = 0, ms = true;
        else rs[i] = b/w;
    }
    if(ms) return cout<<"Many solutions"<<endl, 0;
    for(int i=0;i<n;i++) cout<<int(rs[i]+0.5)<<endl;
    return 0;
}

