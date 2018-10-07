#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n, k; cin>>n>>k;
    ll x = 1, ans = 0;
    while(x < n) x = x * (k + 1), ans++;
    cout<<ans<<endl;
    return 0;
}
