#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 1000010;
bool vis[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    ll n; cin>>n;
    memset(vis, 0, sizeof(vis));
    ll rs = 0;
    for(ll i=2;i<=n;i++) if(!vis[i]) {
            rs++;
            for(ll j=i*i;j<=n;j+=i) vis[j] = true;
        }
    cout<<rs<<endl;
    return 0;
}
