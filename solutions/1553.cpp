#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010, mod = 1000000007;
struct qnode{
    ll l, r, k, id, seg;
}query[maxn];
bool cmp(qnode a, qnode b){ return a.seg != b.seg ? a.seg < b.seg : a.r < b.r; }
ll arr[maxn], num[maxn], cnt[maxn], ans[maxn], po[maxn][105], sgl, n, m;
unordered_set<ll> rc;
void push(ll x){
    cnt[num[x]]--, cnt[++num[x]]++;
    if(num[x] == sgl) rc.insert(x);
}
void pop(ll x){
    if(num[x] == sgl) rc.erase(x);
    cnt[num[x]]--, cnt[--num[x]]++;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    for(ll i=1;i<maxn;i++){
        po[i][0] = 1;
        for(ll j=1;j<105;j++) po[i][j] = (po[i][j-1] * i) % mod;
    }
    int t; cin>>t;
    while(t--){
        memset(cnt, 0, sizeof(cnt)); memset(num, 0, sizeof(num)); rc.clear();
        cin>>n>>m;
        for(ll i=1;i<=n;i++) cin>>arr[i];
        sgl = ll(sqrt(n));
        for(ll i=1;i<=m;i++) {
            cin>>query[i].l>>query[i].r>>query[i].k;
            query[i].id = i, query[i].seg = query[i].l / sgl;
        }
        sort(query + 1, query + m + 1, cmp);
        ll l = 1, r = 0;
        for(ll i=1;i<=m;i++){
            ll ret = 0;
            while(query[i].r > r) push(arr[++r]);
            while(query[i].l < l) push(arr[--l]);
            while(query[i].r < r) pop(arr[r--]);
            while(query[i].l > l) pop(arr[l++]);
            for(ll j=1;j<sgl;j++) ret = (ret + (cnt[j] * po[j][query[i].k]) % mod) % mod;
            for(auto x:rc) ret = (ret + po[num[x]][query[i].k]) % mod;
            ans[query[i].id] = ret;
        }
        for(ll i=1;i<=m;i++) cout<<ans[i]<<endl;
    }
    return 0;
}
