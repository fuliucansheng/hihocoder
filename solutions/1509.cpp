#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 60;
ll arr[maxn], rec[maxn], n;
ll hb(ll x){
    ll rs = -1;
    for(ll i=0;i<maxn;i++) if(x&(ll(1)<<i)) rs = i;
    return rs;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(rec, -1, sizeof(rec));
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        ll r = hb(arr[i]^arr[i-1]);
        if(r != -1){
            ll pa = ((arr[i-1]&(ll(1)<<r)) != 0), na = ((arr[i]&(ll(1)<<r)) != 0);
            if(pa == 1 && na == 0){
                if(rec[r] == 0) return cout<<0<<endl, 0;
                else rec[r] = 1;
            }else if(pa == 0 && na == 1){
                if(rec[r] == 1) return cout<<0<<endl, 0;
                else rec[r] = 0;
            }
        }
    }
    ll rs = 1;
    for(int i=0;i<maxn;i++) if(rec[i] == -1) rs *= 2;
    cout<<rs<<endl;
    return 0;
}
