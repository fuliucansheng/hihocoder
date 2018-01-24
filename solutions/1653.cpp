#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    int m = n*2, arr[n*2];
    for(int i=0;i<m;i++) cin>>arr[i];
    sort(arr, arr+m);
    long long r = arr[m-1];
    for(int i=1;i<n;i++) r += arr[i];
    cout<<r<<endl;
    return 0;
}
