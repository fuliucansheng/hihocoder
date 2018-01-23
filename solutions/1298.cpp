#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 5000010;
ll rec[maxn];
bool vis[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(vis, 0, sizeof(vis));
    for(ll i=0;i<maxn;i++) rec[i] = i;
    for(ll i=2;i<maxn;i++) if(!vis[i]) for(ll j=i*i;j<=maxn;j+=i) vis[j] = true, rec[j] *= (i-1), rec[j] /= i;
    ll l, r, ans = -1; cin>>l>>r;
    for(ll i=l;i<=r;i++) if(ans == -1 || rec[i] < rec[ans]) ans = i;
    cout<<ans<<endl;
    return 0;
}
