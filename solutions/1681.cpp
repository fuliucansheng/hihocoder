#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000010;
int m, n;
struct SAM{
    int ch[maxn][26], fa[maxn], mx[maxn], rc[maxn], ct[maxn];
    int nn, last;
    void init(){
        memset(fa, 0, sizeof(fa)); memset(mx, 0, sizeof(mx));
        memset(ch, 0, sizeof(ch)); memset(rc, 0, sizeof(rc));
        memset(ct, 0, sizeof(ct));
        last = 1, nn = 1;
    }
    void build(int x, int nw){
        int p = last, np = ++nn;
        mx[np] = mx[p] + 1; last = np;
        while(p && !ch[p][x]) ch[p][x] = np, p = fa[p];
        if(!p) fa[np] = 1;
        else{
            int q = ch[p][x];
            if(mx[q] == mx[p] + 1) fa[np] = q;
            else{
                int nq = ++nn; mx[nq] = mx[p] + 1;
                fa[nq] = fa[q]; fa[np] = fa[q] = nq; rc[nq] = rc[q]; ct[nq] = ct[q];
                for(int i = 0;i < 26;i++) ch[nq][i] = ch[q][i];
                while(p && ch[p][x] == q) ch[p][x] = nq, p = fa[p];
            }
        }
        for(;np;np=fa[np]) if(rc[np] != nw) ct[np]++, rc[np] = nw; else break;
    }
} sam;
int main(){
    //freopen("../input.txt","r",stdin);
    sam.init();
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        sam.last = 1;
        for(auto c:s) sam.build(c-'a',i+1);
    }
    int ans = 0;
    for(int i=1;i<=sam.nn;i++) if(sam.ct[i] >= m) ans = max(ans, sam.mx[i]);
    cout<<ans<<endl;
    return 0;
}
