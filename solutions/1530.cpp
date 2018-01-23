#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, p;
ll g(ll bb, ll pp){
    ll r = 0;
    while(true){
        if((r*pp+1)%bb == 0) return (r*pp+1)/bb;
        r++;
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>a>>b>>p;
    ll bp = g(b, p);
    cout<<(a*bp)%p<<endl;
    return 0;
}

