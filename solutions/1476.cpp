#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii bck[10];
int main() {
    //freopen("../input.txt", "r", stdin);
    ll n, m, k; cin>>n>>m>>k;
    for(int i=0;i<k;i++) cin>>bck[i].first>>bck[i].second;
    ll ans = n * (n + 1) / 2 * m * (m + 1) / 2;
    for(int i=1;i<(1<<k);i++){
        int c = __builtin_popcount(i);
        int top = INT32_MAX, bottom = -1, left = INT32_MAX, right = -1;
        for(int j=0;j<k;j++)
            if((1<<j)&i){
                top = min(top, bck[j].first);
                bottom = max(bottom, bck[j].first);
                left = min(left, bck[j].second);
                right = max(right, bck[j].second);
            }
        ll curr = ll(top)*ll(left)*ll(n-bottom+1)*ll(m-right+1);
        if(c%2) ans -= curr; else ans += curr;
    }
    cout<<ans<<endl;
}
