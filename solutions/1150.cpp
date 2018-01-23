#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define du(a, b) ((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second))
#define dc(a, b) (abs(a.first-b.first) + abs(a.second-b.second))
typedef long long ll;
typedef pair<ll,ll> ps;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    for(int ts=1;ts<=t;ts++){
        int m, n, a, b; cin>>n>>m>>a>>b;
        ll x = 0, y = 0;
        ps user[a], comp[b];
        for(int i=0;i<a;i++) cin>>user[i].first>>user[i].second, x += user[i].first, y += user[i].second;
        for(int i=0;i<b;i++) cin>>comp[i].first>>comp[i].second;
        ll ans = -1;
        x /= a, y /= a;
        vector<ps> nbr = { ps(x, y), ps(x+1, y), ps(x, y+1), ps(x+1, y+1)};
        for(auto nb:nbr){
            ll rs = 0, mn = -1;
            for(int i=0;i<a;i++) rs += du(nb, user[i]);
            for(int i=0;i<b;i++) mn = (mn == -1 ? dc(nb, comp[i]) : min(mn, dc(nb, comp[i])));
            if(ans == -1 || (rs + mn) < ans) ans = rs + mn;
        }
        cout<<"Case #"<<ts<<": "<<ans<<endl;
    }
    return 0;
}
