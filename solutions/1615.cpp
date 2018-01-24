#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 300;
int arr[maxn][maxn];
int sum[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(sum, 0, sizeof(sum));
    int n, res = 0;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) sum[j] += arr[i][j];
    sort(sum,sum+n);
    vector<int> rest;
    for(int i=0;i+1<n;i+=2) res += abs(sum[i] + sum[i+1]);
    if(n % 2 == 1) res += sum[n-1];
    cout<<res<<endl;
    return 0;
}
