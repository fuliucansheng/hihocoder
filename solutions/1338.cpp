#include <iostream>
#include <cstring>
using namespace std;
const int N = 1000;
int arr[N];
int res[N][N], sum[N][N];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(sum, 0, sizeof(sum));
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i], res[i][i] = arr[i], sum[i][i] = arr[i];
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) sum[i][j] = sum[i][j-1] + arr[j];
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++) res[i][j] = sum[i][j] - min(res[i+1][j],res[i][j-1]);
    }
    cout<<res[0][n-1]<<endl;
    return 0;
}
