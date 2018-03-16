#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int arr[maxn];
int main() {
    //freopen("../input.txt","r",stdin);
    memset(arr, 0, sizeof(arr));
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        arr[x] = i;
    }
    bool status = false;
    for(int i=n;i>0;i--) if(arr[i] < arr[i-1]) {
            cout<<i-1<<endl, status = true;
            break;
        }
    if(!status) cout<<0<<endl;
    return 0;
}