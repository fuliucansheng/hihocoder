#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int arr[maxn], pre[maxn], suf[maxn], rc[maxn], p, n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    memset(pre, 0, sizeof(pre)); memset(suf, 0, sizeof(suf));
    for(int i=0;i<n;i++) cin>>arr[i];
    p = 0, memset(rc, 0x3f, sizeof(rc));
    for(int i=0;i<n;i++) {
        if(arr[i] <= rc[p]) rc[++p] = arr[i], pre[i] = p;
        else {
            auto dx = upper_bound(rc, rc + p, arr[i], greater<int>()) - rc;
            rc[dx] = arr[i], pre[i] = p;
        }
    }
    p = 0, memset(rc, 0, sizeof(rc));
    for(int i=n-1;i>=0;i--) {
        if(arr[i] > rc[p]) rc[++p] = arr[i], suf[i] = p;
        else {
            auto dx = upper_bound(rc, rc + p, arr[i]) - rc;
            rc[dx] = arr[i], suf[i] = p;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, pre[i] + suf[i+1]);
    cout<<ans<<endl;
    return 0;
}
