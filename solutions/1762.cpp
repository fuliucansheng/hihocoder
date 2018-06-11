#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vs[10];
ll len, a, lmt, ans, ds;
void dfs(ll pre, ll h) {
    if(h == len) {
        ll d = min(abs(a - pre), abs(lmt - abs(a - pre)));
        if(d > ds || (d == ds && pre < ans)) ans = pre, ds = d;
        return ;
    }
    for(int i = 0; i < 10; i++) if(!vs[i]) {
        vs[i] = true;
        dfs(pre * 10 + i, h + 1);
        vs[i] = false;
    }
}
int main() {
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    len = ll(s.length()), a = atol(s.c_str()), lmt = ll(pow(10, len));
    memset(vs, 0, sizeof(vs)), ans = 0x3f3f3f3f3f3f3f3f, ds = 0;
    dfs(0, 0);
    string aa = to_string(ans);
    for(int i = 0; i < len - aa.length(); i++) cout<<0;
    cout<<ans<<endl;
    return 0;
}
