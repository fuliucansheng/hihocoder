#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1000010;
ll n, k, arr[maxn];
ll find(ll l, ll r){
    ll st = arr[l], L = l + 1, R = r, p = l;
    while(L <= R){
        if(arr[L] < st) arr[p++] = arr[L++];
        else if(arr[R] < st) arr[p++] = arr[R], arr[R--] = arr[L++];
        else R--;
    }
    arr[p] = st;
    if(p == k) return arr[k];
    return p > k ? find(l, p - 1) : find(p + 1, r);
}
int main(){
    //freopen("../input.txt","r",stdin);
    scanf("%lld%lld", &n, &k); k--;
    for(ll i=0;i<n;i++) scanf("%lld", &arr[i]);
    if(k > n) cout<<-1<<endl;
    else cout<<find(0, n - 1)<<endl;
    return 0;
}