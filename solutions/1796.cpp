#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("../input.txt", "r", stdin);
    int n, k; cin>>n>>k;
    int ans = 0;
    map<int,int> mp;
    for(int i = 0, x; i < n; i++) {
        cin>>x;
        int rx = (k - (x % k)) % k, xx = x % k;
        mp[xx]++;
        if(mp[rx]) {
            if(xx == rx) ans = max(ans, mp[xx]);
            else ans = max(ans, 2);
        }
    }
    cout<<(ans < 2 ? -1 : ans)<<endl;
    return 0;
}
