#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("../input.txt", "r", stdin);
    string a, b, c; cin>>a>>b>>c;
    int sz = int(a.size()), ans = 0;
    for(int i = 0; i < sz; i++) {
        if(a[i] != b[i]) {
            if(a[i] != c[i]) ans += (b[i] == c[i] ? 1 : 2);
            else ans += 1;
        } else {
            if(a[i] != c[i]) ans += 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
