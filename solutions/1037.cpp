#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("../input.txt","r",stdin);
    int n,res = 0;
    cin>>n;
    int arr[n+1],num;
    memset(arr,0,sizeof(arr));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<(n-i);j++){
            cin>>num;
            arr[i+j] = num + max(arr[i+j], arr[i+j+1]);
            if(arr[j] > res) res = arr[j];
        }
    }
    cout<<res<<endl;
    return 0;
}
