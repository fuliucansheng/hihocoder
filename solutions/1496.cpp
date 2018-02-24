#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int v[2];
    node operator +(const node& b) const{
        int vv[2] = {v[0], v[1]};
        for(int i=0;i<2;i++){
            if(b.v[i] > vv[0]) vv[1] = vv[0], vv[0] = b.v[i];
            else if(b.v[i] > vv[1]) vv[1] = b.v[i];
        }
        return node{vv[0], vv[1]};
    }
}dp[(1<<20)+10];
int main(){
    //freopen("../input.txt", "r", stdin);
    int t, n; cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<(1<<20);i++) dp[i] = node{0, 0};
        for(int i=0,x;i<n;i++) cin>>x, dp[x] = dp[x] + node{x, 0};
        for(int i=0;i<20;i++) for(int j=0;j<(1<<20);j++) if(~j&(1<<i)) dp[j] = dp[j] + dp[j|(1<<i)];
        ll ans = 0;
        for(int i=0;i<(1<<20);i++) ans = max(ans, ll(i)*ll(dp[i].v[0])*ll(dp[i].v[1]));
        cout<<ans<<endl;
    }
    return 0;
}
