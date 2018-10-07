#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 200010;
struct node {
    ll id, a, b;
} p[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n; cin>>n;
    for(ll i = 0; i < 2 * n + 1; i++) {
        cin>>p[i].a>>p[i].b;
        p[i].id = i + 1;
    }
    sort(p, p + 2 * n + 1, [](node& x, node& y) { return x.a > y.a; });
    cout<<p[0].id<<endl;
    for(int i = 1; i < 2 * n + 1; i += 2) cout<<(p[i].b > p[i + 1].b ? p[i].id : p[i + 1].id)<<endl;
    return 0;
}
