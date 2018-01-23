#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    int arr[n], min_num = INT32_MAX;
    long long res = 0;
    for(int i=0;i<n;i++) cin>>arr[i], min_num = min(min_num, arr[i]);
    for(int i=0;i<n;i++) res += (long long)(arr[i]-min_num);
    cout<<res<<endl;
    return 0;
}
