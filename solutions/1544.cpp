#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int rc[maxn], n, m, t, k1, k2;
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(rc, 0, sizeof(rc));
    cin>>n>>m>>t>>k1>>k2;
    bool status = true;
    for(int i=0;i<n;i++) {
        int a, b; cin>>a>>b;
        if(k1 * (b - a) > m || k2 > m) status = false;
        for(int k=a;k<b;k++) rc[k] = 1;
    }
    if(!status) return cout<<-1<<endl, 0;
    int ans = 0, chg = 0;
    for(int i=0;i<t;i++){
        if(rc[i]){
            if(chg < k1) chg = m, ans++;
            chg -= k1;
        }else{
            if(chg < k2) chg = m, ans++;
            chg -= k2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
