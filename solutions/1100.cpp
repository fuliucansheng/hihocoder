#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int arr[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int m,n,r,h;
    cin>>n>>m>>h>>r;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    int count = 0, res = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > (r + count) || (i > 0 && (arr[i] - arr[i-1]) > m))
            res += count, count = (arr[i] > r ? 0 : 1);
        else count++;
    }
    res += count;
    res = min(res, h);
    cout<<res<<endl;
    return 0;
}
