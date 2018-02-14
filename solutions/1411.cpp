#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1010;
ll arr[maxn], n;
bool vis[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    ll s = 0;
    for(ll i=0;i<n;i++) cin>>arr[i], s += arr[i];
    if(s < 0) return cout<<"Impossible"<<endl, 0;
    memset(vis, 0, sizeof(vis));
    ll pre = 0, ans[n], x = 0;
    for(ll i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!vis[j] && pre + arr[j] >= 0) {
                ans[x++] = j, pre += arr[j], vis[j] = 1;
                break;
            }
    for(ll i=0;i<n;i++) cout<<ans[i]+1<<" "; cout<<endl;
    return 0;
}
