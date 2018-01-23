#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll g(ll x){
    ll lmt = ll(sqrt(2*x));
    for(ll i=lmt;i>0;i--) {
        if((2*x)%i == 0 && ((((2*x)/i)-i)%2)) return i;
    }
    return 1;
}
int main(){
    //freopen("../input.txt","r",stdin);
    ll n, t; cin>>t;
    while(t--){
        cin>>n;
        cout<<g(n)<<endl;
    }
    return 0;
}

