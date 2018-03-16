#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100050;
int arr[maxn], rec[maxn], n;
int lowbit(int x){ return x&-x; }
void update(int x){
    while(x < maxn) rec[x]++, x += lowbit(x);
}
ll query(int x){
    ll r = 0;
    while(x > 0) r += rec[x], x -= lowbit(x);
    return r;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(arr, 0, sizeof(arr));memset(rec, 0 , sizeof(rec));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i], update(arr[i]);
    ll res = 0;
    for(int i=1;i<=n;i++){
        double l = 1/8.0*arr[i]+8, r = 8.0*arr[i]+8;
        if(arr[i] < 88888) r = min(r, 88888.0);
        r = min(r, double(maxn-1));
        int ql = (floor(l) == l ? floor(l-1) : floor(l)), qr = floor(r);
        res += query(qr) - query(ql);
        if(arr[i] > ql && arr[i] <= qr) res--;
    }
    cout<<res<<endl;
    return 0;
}
