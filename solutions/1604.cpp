#include <iostream>
using namespace std;
const int maxn = 1000010;
int arr[maxn], n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int rs = 0, mx = arr[n-1];
    for(int i=n-2;i>=0;i--)
        if(arr[i] > mx) mx = arr[i];
        else rs += mx - arr[i];
    cout<<rs<<endl;
    return 0;
}
