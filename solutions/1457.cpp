#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = (1000000+50)<<1, mod = 1e9+7;
int in[maxn][11], fa[maxn], mx[maxn], deg[maxn];
ll ct[maxn], cnt[maxn];
int nn, last;
void build(int x){
    int p=last,np=++nn;
    mx[np]=mx[p]+1;
    while(p&&!in[p][x]) in[p][x]=np, p=fa[p];
    if(!p) fa[np] = 1;
    else{
        int q=in[p][x];
        if(mx[q]==mx[p]+1) fa[np]=q;
        else{
            int nq=++nn;mx[nq]=mx[p]+1;
            fa[nq]=fa[q];
            fa[np]=fa[q]=nq;
            for(int i=0;i<11;i++) in[nq][i]=in[q][i];
            while(p&&in[p][x]==q) in[p][x]=nq, p=fa[p];
        }
    }
    last=np;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(fa, 0, sizeof(fa)); memset(mx, 0, sizeof(mx)); memset(in, 0, sizeof(in));
    memset(ct, 0, sizeof(ct)); memset(deg, 0, sizeof(deg)); memset(cnt, 0, sizeof(cnt));
    int n;
    cin>>n;
    last = 1, nn = 1;
    string s = "", sp;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        cin>>sp;
        if(i == 0) s = sp;
        else s += ":", s += sp;
    }
    for(auto c:s) build(c-'0');
    for(int i=1;i<=nn;i++) for(int j=0;j<11;j++) if(in[i][j]) deg[in[i][j]]++;
    queue<int> Q;
    Q.push(1), ct[1] = 1;
    while(!Q.empty()){
        int u = Q.front();Q.pop();
        for(int i=0;i<11;i++){
            int v = in[u][i];
            if(!v) continue;
            deg[v]--;
            ll vc = (i == 10 ? 0 : ct[u]);
            ct[v] = (ct[v] + vc) % mod;
            if(vc) cnt[v] = ((cnt[v] + cnt[u]*10%mod) + vc*i)%mod;
            if(!deg[v]) Q.push(v), ans += cnt[v], ans %= mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
