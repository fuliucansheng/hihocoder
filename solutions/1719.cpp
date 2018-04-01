#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 1010, maxm = 101;
ll arr[maxn][maxm], vv[maxn], ans = 0, n, m, p;
int id[maxn];
vector<pii> vec;
bool cmp(int a, int b){
    return vv[a] > vv[b];
}
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
ll inv(ll x, ll mod) {
    return qpow(x, mod - 2, mod);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(vv, 0, sizeof(vv));
    cin>>n>>m>>p;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin>>arr[i][j], vv[i] += arr[i][j] * arr[i][j];
        id[i] = i;
    }
    sort(id, id + n, cmp);
    for(int i=0;i<n;i++) {
        int x = id[i];
        for(auto v:vec) {
            int y = v.first, z = v.second;
            if(arr[x][z]) {
                ll tmp = arr[x][z] * inv(arr[y][z], p) % p;
                for(int k = 0; k < m; k++) arr[x][k] = (arr[x][k] - arr[y][k] * tmp % p + p) % p;
            }
        }
        int ok = -1;
        for(int j=0;j<m;j++) if(arr[x][j]) {
                ok = j;
                break;
            }
        if(ok != -1){
            for(auto v:vec){
                int y = v.first;
                if(arr[y][ok]){
                    ll tmp = arr[y][ok] * inv(arr[x][ok], p) % p;
                    for(int k = 0; k < m; k++) arr[y][k] = (arr[y][k] - arr[x][k] * tmp % p + p) % p;
                }
            }
            vec.push_back(pii(x, ok));
            ans += vv[x];
        }
    }
    cout<<ans<<endl;
    return 0;
}
