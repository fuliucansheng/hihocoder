#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int a[maxn], n;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 0; i < n; i++) cin>>a[i];
        sort(a, a + n);
        map<int,int> mp0, mp1, mp;
        for(int i = 0; i < n; i++) {
            int pa = a[i] - 1;
            if(mp0[pa]) mp0[pa]--, mp1[a[i]]++;
            else if(mp1[pa]) mp1[pa]--, mp[a[i]]++;
            else if(mp[pa]) mp[pa]--, mp[a[i]]++;
            else mp0[a[i]]++;
        }
        bool status = true;
        for(auto &p : mp0) if(p.second) {
            status = false;
            break;
        }
        if(status) {
            for(auto &p : mp1) if(p.second) {
                    status = false;
                    break;
                }
        }
        cout<<(status ? "YES" : "NO")<<endl;
    }
    return 0;
}
