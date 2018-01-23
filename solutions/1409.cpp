#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int arr[maxn], rec[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i], rec[i] = arr[i];
    sort(rec, rec+n);
    int l = 0, r = n - 1;
    while(arr[l] == rec[l]) l++;
    while(arr[r] == rec[r]) r--;
    cout<<r-l+1<<endl;
    return 0;
}
