#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int a[maxn], n, k;
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n>>k;
    for(int i = 0; i < k; i++) cin>>a[i];
    sort(a, a + k);
    int nn = n / 2 + n % 2;
    ll ret = 0;
    for(int i = 0; i < k; i++) {
        int e = a[i] + nn;
        if(e > n) e -= n;
        int dx = int(lower_bound(a, a + k, e) - a);
        int c = dx > i ? dx - i - 1 : dx + k - i - 1;
        ret += ll(c) * ll(c - 1) / 2;
    }
    cout<<ret<<endl;
    return 0;
}
