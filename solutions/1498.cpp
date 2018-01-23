#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n, q; cin>>n>>q;
    ll rs = 0, m = 1;
    while(m*q*2 < n) rs += q, m *= 2;
    cout<<rs+ceil(double(n)/m)<<endl;
    return 0;
}
