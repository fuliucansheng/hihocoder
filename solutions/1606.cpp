#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac;
bool v[1000000];
ll fast_mod(ll x, ll y, ll p){
    ll ret = 1;
    while(y){
        if(y & 1) ret = (ret * x) % p;
        y >>= 1, x = x * x % p;
    }
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    memset(v, 0, sizeof(v));
    for(ll i=2;i<1000000;i++){
        if(!v[i]){
            fac.push_back(i);
            for(ll j=i*2;j<1000000;j+=i) v[j] = true;
        }
    }
    int t; cin>>t;
    while(t--){
        ll n, a, b, p = -1, phi; cin>>n;
        ll sqrn = ll(sqrt(n)) + 1;
        bool status = false;
        for(ll i=2;i<sqrn;i++) if(n % i == 0) {
                p = i, phi = n / i * (i - 1);
                break;
            }
        if(p == -1) phi = n - 1;
        if(phi % 3 == 0){
            for(auto f:fac){
                a = fast_mod(f, phi/3, n);
                if(a != 1) {
                    b = a * a % n, status = true;
                    break;
                }
            }
        }else status = false;
        if(status) cout<<1<<" "<<min(a,b)<<" "<<max(a,b)<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
