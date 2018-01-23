#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 45, maxl = 1100000;
ll arr[maxn], cnt[maxn], ans = 0;
int psz, ssz, nsz;
struct node{
    ll d, c;
    node(){}
    node(ll d, ll c):d(d),c(c){}
} pre[maxl], suf[maxl], num[maxn], tmp[maxl];
ll g(int lmt){
    int mid = nsz / 2;
    psz = ssz = 0, pre[psz++] = node(0,0), suf[ssz++] = node(0,0);
    for(int i=0;i<mid;i++){
        int pz = psz;
        for(int j=0;j<pz;j++) tmp[j] = pre[j];
        for(int j=0;j<pz;j++) if(abs(pre[j].c + num[i].c) <= lmt) tmp[psz++] = node(pre[j].d + num[i].d, pre[j].c + num[i].c);
        int pl = 0, pr = pz, p = 0;
        while(p < psz) {
            if(pl == pz) pre[p++] = tmp[pr++];
            else if(pr == psz) pre[p++] = tmp[pl++];
            else {
                if(tmp[pl].d >= tmp[pr].d) pre[p++] = tmp[pl++];
                else pre[p++] = tmp[pr++];
            }
        }
    }
    for(int i=mid;i<nsz;i++){
        int sz = ssz;
        for(int j=0;j<sz;j++) tmp[j] = suf[j];
        for(int j=0;j<sz;j++) if(abs(suf[j].c + num[i].c) <= lmt) tmp[ssz++] = node(suf[j].d + num[i].d, suf[j].c + num[i].c);
        int pl = 0, pr = sz, p = 0;
        while(p < ssz) {
            if(pl == sz) suf[p++] = tmp[pr++];
            else if(pr == ssz) suf[p++] = tmp[pl++];
            else {
                if(tmp[pl].d <= tmp[pr].d) suf[p++] = tmp[pl++];
                else suf[p++] = tmp[pr++];
            }
        }
    }
    ll rs = 0, s = 0;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0;i<psz;i++){
        node p = pre[i];
        while(s < ssz && suf[s].d + p.d <= 0) cnt[suf[s++].c+21]++;
        rs += cnt[21-p.c];
    }
    return rs;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i], arr[i]<<=1;
    sort(arr, arr+n);
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++){
            ll x = (arr[i] + arr[j]) >> 1;
            psz = ssz = nsz = 0;
            for(int k=0;k<i;k++) num[nsz++] = node(arr[k]-x, -1);
            for(int k=j+1;k<n;k++) num[nsz++] = node(arr[k]-x, 1);
            ans += g(min(i, n-j));
        }
    cout<<ans<<endl;
    return 0;
}
