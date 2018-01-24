#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    int arr[n], l = 0, r = n-1, c = 1;
    for(int i=0;i<n;i++){
        if(i%2 == 0) arr[l++] = c++;
        else arr[r--] = c++;
    }
    for(int i=0;i<n;i++) cout<<(i == 0 ? "" : " ")<<arr[i];
    cout<<endl;
    return 0;
}
