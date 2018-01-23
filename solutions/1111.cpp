#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        map<ll,ll> cnt;
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int u; cin>>u;
            cnt[u]++;
        }
        ll p = -1, rs = 1;
        while(!cnt.empty()){
            auto u = cnt.begin();
            ll k = u->first, c = u->second;
            cnt.erase(cnt.begin());
            if(p != -1 && c) cnt[k+p]++, rs = rs * 2 * c % mod, c--, p = -1;
            if(c && c % 2 == 0){
                cnt[2*k] += c/2;
                while(c) rs = rs * (c - 1) * 2 % mod, c -= 2;
            }
            if(c > 1 && c % 2 == 1){
                rs = rs * c % mod, cnt[2*k] += (c - 1)/2; c--;
                while(c) rs = rs * (c - 1) * 2 % mod, c -= 2;
                c = 1;
            }
            if(c == 1) p = k, c--;
        }
        cout<<(rs >= 0 ? rs : rs + mod)<<endl;
    }
    return 0;
}
