#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 14;
int ans[maxn], rec[maxn], cnt[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    string s; cin>>s;
    int l = 1 << n;
    for(int i=0;i<l;i++) cnt[i] = __builtin_popcount(i);
    for(int i=0;i<l;i++) ans[i] = n;
    for(int i=0;i<l;i++){
        memset(rec, 0, sizeof(rec));
        for(int j=0;j<l;j++) rec[j&i] |= (1<<(s[j]-'0'));
        for(int j=0;j<l;j++) if(rec[j&i] == 1 || rec[j&i] == 2) ans[j] = min(ans[j], cnt[i]);
    }
    for(int i=0;i<l;i++) cout<<ans[i]<<" "; cout<<endl;
    return 0;
}
