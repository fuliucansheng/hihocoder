#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int arr[maxn], rec[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i=n;i>0;i--) cin>>arr[i];
    rec[1] = arr[1];
    int len = 1;
    for(int i=2;i<=n;i++){
        if(arr[i] >= rec[len]) rec[++len] = arr[i];
        else{
            int j = upper_bound(rec+1, rec+len+1, arr[i]) - rec;
            rec[j] = arr[i];
        }
    }
    cout<<n - len<<endl;
    return 0;
}

