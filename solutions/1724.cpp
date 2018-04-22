#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int arr[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    int n, p, q, k; cin>>n>>p>>q>>k;
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr + n, greater<int>());
    int ret = 0;
    if(k == 0 || p == n - 1) {
        for(int i = 0; i <= p; i++) ret += arr[i];
        for(int i = p + 1; i < n; i++) ret -= arr[i];
    }else{
        for(int i = 0; i < n - 1; i++) ret += arr[i];
        ret -= arr[n - 1];
    }
    cout<<ret<<endl;
    return 0;
}
