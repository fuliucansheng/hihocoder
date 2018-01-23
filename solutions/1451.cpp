#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
ll g(ll m){
    ll rs = 1, q = 4;
    while(m){
        if(m&1) rs *= q, rs %= mod;
        q *= q, q %= mod;
        m >>= 1;
    }
    return rs >= 0 ? rs : rs + mod;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    ll arr[100];
    arr[1] = 1, arr[2] = 2, arr[3] = 3, arr[4] = 4, arr[5] = 5, arr[6] = 6, arr[7] = 9;
    for(int i=8;i<20;i++) arr[i] = max(max(2*arr[i-3], 3*arr[i-4]), max(4*arr[i-5], 5*arr[i-6]));
    if(n >= 20){
        ll c = n/5, m = n%5;
        ll t = c-3, x = 3*5+m;
        ll r = (t > 0 ? g(t) : 1);
        cout<<(r*arr[x])%mod<<endl;
    }
    else cout<<arr[n]<<endl;
    return 0;
}
