#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 25;
ll h[maxn], i[maxn], o[maxn];
char dfs_i(ll n, ll k);
char dfs_o(ll n, ll k);
char dfs_h(ll n, ll k){
    if(n == 0) return 'h';
    if(h[n-1] >= k) return dfs_h(n-1,k); k -= h[n-1];
    if(i[n-1] >= k) return dfs_i(n-1,k); k -= i[n-1];
    return dfs_o(n-1,k);
}
char dfs_i(ll n, ll k){
    if(n == 0) return 'i';
    if(h[n-1] >= k) return dfs_h(n-1,k); k -= h[n-1];
    return dfs_i(n-1,k);
}
char dfs_o(ll n, ll k){
    if(n == 0) return 'o';
    if(h[n-1] >= k) return dfs_h(n-1,k); k -= h[n-1];
    return dfs_o(n-1,k);
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(h, 0, sizeof(h)); memset(i, 0, sizeof(i)); memset(o, 0, sizeof(o));
    h[0] = i[0] = o[0] = 1;
    for(int k=1;k<maxn;k++){
        h[k] = h[k-1] + i[k-1] + o[k-1];
        i[k] = h[k-1] + i[k-1];
        o[k] = h[k-1] + o[k-1];
    }
    int t; cin>>t;
    while(t--){
        ll n, k; cin>>n>>k;
        ll r = min(n-1, ll(24));
        if(k && h[r] >= k) cout<<dfs_h(r, k)<<endl, k = 0; else if(k) k -= h[r];
        if(k && i[r] >= k) cout<<dfs_i(r, k)<<endl, k = 0; else if(k) k -= i[r];
        if(k && h[r] >= k) cout<<dfs_h(r, k)<<endl, k = 0; else if(k) k -= h[r];
        if(k && o[r] >= k) cout<<dfs_o(r, k)<<endl, k = 0; else if(k) k -= o[r];
        if(k) cout<<-1<<endl;
    }
    return 0;
}
