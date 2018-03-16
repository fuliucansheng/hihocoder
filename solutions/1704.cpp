#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010;
ll arr[maxn], pre[maxn], suf[maxn], n;
int main(){
    //freopen("../input.txt","r",stdin);
    memset(arr, 0, sizeof(arr)); memset(pre, 0, sizeof(pre));
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>arr[i], pre[i] = pre[i-1] + arr[i], suf[i] = 1;
    ll mn = pre[n], ans = -1;
    for(ll i=n;i>=1;i--){
        if(i == n && arr[i] <= 0) suf[i] = 0;
        if(i < n && (pre[i] > mn || arr[i] <= 0)) suf[i] = 0;
        mn = min(mn, pre[i]);
    }
    mn = pre[1];
    for(ll i=1;i<=n;i++){
        if(suf[i] && mn + pre[n] - pre[i-1] > 0) {
            ans = i;
            break;
        }
        mn = min(pre[i], mn);
    }
    cout<<ans<<endl;
    return 0;
}
