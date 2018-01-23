#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll m, n;
void dfs(ll &rr, ll xx, ll ss, ll mm){
    if(ss == n){
        if(mm % m == 0) rr++;
        return;
    }
    for(ll x=xx+1;x<=n-ss;x++) dfs(rr, x, ss + x, mm * x);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    ll rs = 0;
    dfs(rs, 0, 0, 1);
    cout<<rs<<endl;
    return 0;
}
