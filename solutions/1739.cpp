#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn = 100010;
pll aa[maxn];
ll ins[66];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i = 1; i < n; i++) {
        ll u, v, a, t; cin>>u>>v>>a>>t;
        aa[i] = { u ^ v ^ t, a };
    }
    sort(aa + 1, aa + n, greater<pll>()); memset(ins, 0, sizeof(ins));
    __int128 ans = 0, sum = 0, c = 0;
    for(int i = 1; i < n; i++) {
        sum += __int128(aa[i].first);
        if(aa[i].second == 1) continue;
        c++;
        for(ll k = 63; k >= 0; k--) if(aa[i].second >> k) {
                if(!ins[k]) {
                    ins[k] = aa[i].second;
                    break;
                }
                aa[i].second ^= ins[k];
            }
        if(aa[i].second) ans += __int128(aa[i].first);
    }
    if(!c) cout<<"No"<<endl;
    else {
        ans = sum - ans;
        string s = "";
        while (ans) {
            s += '0' + ans % 10;
            ans /= 10;
        }
        if (s == "") s = "0";
        reverse(s.begin(), s.end());
        cout<<s<<endl;
    }
    return 0;
}
