#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vs[40000];
vector<ll> pm;
int main(){
    //freopen("../input.txt", "r", stdin);
    pm.push_back(1);
    for(ll i = 2; i < 40000; i++) if(!vs[i]) {
        pm.push_back(i);
        for(ll j = i; j < 40000; j += i) vs[j] = true;
    }
    ll n, k, mxp; cin>>n>>k;
    for(auto p : pm) if(k % p == 0) mxp = p;
    if(mxp == 1) mxp = k;
    ll m = 0, c = 0;
    while(k % mxp == 0) k /= mxp, c++;
    while(n) m += n / mxp, n /= mxp;
    cout<<m / c<<endl;
    return 0;
}
