#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
int arr[maxn][maxn], sum[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(sum, 0, sizeof(sum));
    int n, ans = 0;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) sum[j] += arr[i][j];
    sort(sum,sum+n);
    for(int i=0;i+1<n;i+=2) ans += abs(sum[i] + sum[i+1]);
    if(n % 2 == 1) ans += sum[n-1];
    cout<<ans<<endl;
    return 0;
}