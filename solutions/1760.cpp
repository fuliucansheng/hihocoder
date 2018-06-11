#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int _ = 0; _ < n; _++) {
        string s, t; cin>>s>>t;
        int ssz = int(s.length()), tsz = int(t.length());
        string s1, s2;
        for(int i = 0; i < ssz; i += 2) s1 += s[i];
        for(int i = 1; i < ssz; i += 2) s2 += s[i];
        int r1 = 0, r2 = 0, s1sz = int(s1.length()), s2sz = int(s2.length());
        for(int i = 0; i < tsz; i++) {
            if(r1 < s1sz && t[i] == s1[r1]) r1++;
            if(r2 < s2sz && t[i] == s2[r2]) r2++;
        }
        cout<<((r1 == s1sz || r2 == s2sz) ? "Yes" : "No")<<endl;
    }
    return 0;
}
