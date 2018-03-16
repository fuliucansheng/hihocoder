#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    int arr[n], min_num = INT32_MAX;
    ll res = 0;
    for(int i=0;i<n;i++) cin>>arr[i], min_num = min(min_num, arr[i]);
    for(int i=0;i<n;i++) res += (ll)(arr[i]-min_num);
    cout<<res<<endl;
    return 0;
}
