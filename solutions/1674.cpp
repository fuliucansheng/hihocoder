#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int arr[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, k; cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    int rs = 0;
    for(int i=0;i+2<n;){
        if(arr[i+2] - arr[i] <= k) rs++, i+=3;
        else i++;
    }
    cout<<rs<<endl;
    return 0;
}
