#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
ll m[maxn], r[maxn];
ll extend_gcd(ll a, ll b, ll& x, ll& y){
    if(b == 0) return x = 1, y = 0, a;
    ll d = extend_gcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
int main() {
    //freopen("../input.txt", "r" , stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>m[i]>>r[i];
    ll M = m[0], R = r[0], x, y;
    for(int i=1;i<n;i++){
        ll d = __gcd(M, m[i]), c = r[i] - R;
        if(c % d) return cout<<-1<<endl, 0;
        extend_gcd(M/d, m[i]/d, x, y);
        x = (c / d * x) % (m[i] / d), R += x * M, M = M / d * m[i], R %= M;
    }
    if(R < 0) R += M;
    cout<<R<<endl;
    return 0;
}
