#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n; cin>>n;
    if(n == 1) return cout<<2<<endl, 0;
    n *= 2;
    ll s = n * (n+1) / 2, ss = 1 - n + 2 - n + 1;
    ll rr = s + ss;
    ll r = (rr % 2 == 0) ? (rr / 2) : (rr / 2 + 1);
    cout<<(s - r)<<endl;
    return 0;
}
