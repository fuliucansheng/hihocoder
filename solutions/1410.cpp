#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    //freopen("../input.txt", "r", stdin);
    ll n; cin>>n;
    vector<int> rc;
    int p = 0, ans = 0;
    while(n){
        if(n&1) rc.push_back(p);
        n >>= 1, p++;
    }
    int c = 1;
    for(int i=0;i+1<int(rc.size());i++){
        if(rc[i+1] - rc[i] == 1) c++;
        else{
            if(c > 1) ans++, rc[i] = rc[i] + 1, i--;
            else ans++;
            c = 1;
        }
    }
    if(c > 1) ans++;
    cout<<ans+1<<endl;
    return 0;
}
