#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f3f3f3f3f
typedef long long ll;
const int maxn = 50010;
int a[maxn], n, k;
struct node {
    ll mx_f = -inf, mx_s = -inf, mx_t = -inf;
    ll mn_f = inf, mn_s = inf, mn_t = inf;
    void mx_upd(ll x) {
        if(mx_f < x) mx_t = mx_s, mx_s = mx_f, mx_f = x;
        else if(mx_s < x) mx_t = mx_s, mx_s = x;
        else if(mx_t < x) mx_t = x;
    }
    void mn_upd(ll x) {
        if(mn_f > x) mn_t = mn_s, mn_s = mn_f, mn_f = x;
        else if(mn_s > x) mn_t = mn_s, mn_s = x;
        else if(mn_t > x) mn_t = x;
    }
    ll calc() {
        ll ret = 0;
        ret += (mx_f == -inf || mn_f == inf) ? 0 : max(mx_f - mn_f, ll(0));
        if(k == 1) return ret;
        ret += (mx_s == -inf || mn_s == inf) ? 0 : max(mx_s - mn_s, ll(0));
        if(k == 2) return ret;
        ret += (mx_t == -inf || mn_t == inf) ? 0 : max(mx_t - mn_t, ll(0));
        return ret;
    }
} aa[maxn];
ll pre[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]), pre[i] = a[i] + (i ? pre[i - 1] : 0);
        if(i) aa[i] = aa[i - 1], aa[i].mn_upd(a[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--) {
        aa[i].mx_f = aa[i + 1].mx_f, aa[i].mx_s = aa[i + 1].mx_s, aa[i].mx_t = aa[i + 1].mx_t;
        aa[i].mx_upd(a[i + 1]);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, pre[i] + aa[i].calc());
    cout<<ans<<endl;
    return 0;
}
