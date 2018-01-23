#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    int arr[n], r=n-1;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(r;r>0;r--) if(arr[r-1]>arr[r]) break;
    if(r == 0) cout<<arr[0]<<endl;
    else {
        for(int i=0;i<r;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
