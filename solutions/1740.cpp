#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--) {
        string a, b; cin>>a>>b;
        int n = int(a.size());
        bool status = true;
        map<char,char> rc;
        for(int i = 0; i < n; i++) {
            if(rc.count(a[i]) && rc[a[i]] != b[i]) status = false;
            rc[a[i]] = b[i];
        }
        cout<<(status ? "YES" : "NO")<<endl;
    }
    return 0;
}
