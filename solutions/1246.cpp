#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const ll maxn = 2010;
ll num[6000], sum[maxn], ans[maxn], n, c = 0;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    sum[0] = 0;
    for(ll i=1;i<=n;i++) cin>>sum[i], sum[i] += sum[i-1];
    for(ll i=1;i*i<=sum[n];i++)
        if(sum[n]%i == 0) {
            num[c++] = i;
            if(i*i != sum[n]) num[c++] = sum[n]/i;
        }
    sort(num, num+c);
    ll k = 1;
    for(ll i=c-1;i>=0;i--){
        ll m = num[i], r = 0;
        map<ll,ll> cnt;
        for(ll j=1;j<=n;j++) r = max(r, ++cnt[sum[j]%m]);
        while(k <= r) ans[k] = m, k++;
    }
    for(ll i=1;i<=n;i++) cout<<ans[i]<<endl;
    return 0;
}

