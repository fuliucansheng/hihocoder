#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    map<int,int> mp0, mp1;
    int c0 = 0, c1 = 0;
    for(int i = 0, x; i < n; i++) {
        char ch; cin>>ch>>x;
        if(ch == 'A') {
            if(c0 && x > mp0.rbegin()->first) mp1[x]++, c1++;
            else mp0[x]++, c0++;
        } else {
            if(mp0.count(x)) {
                mp0[x]--, c0--;
                if(mp0[x] == 0) mp0.erase(x);
            }
            else if(mp1.count(x)) {
                mp1[x]--, c1--;
                if(mp1[x] == 0) mp1.erase(x);
            }
        }
        if(c0 - c1 > 1) {
            int p0 = mp0.rbegin()->first;
            mp1[p0]++, c1++;
            mp0[p0]--, c0--;
            if(mp0[p0] == 0) mp0.erase(p0);
        } else if(c1 - c0 > 1) {
            int p1 = mp1.begin()->first;
            mp0[p1]++, c0++;
            mp1[p1]--, c1--;
            if(mp1[p1] == 0) mp1.erase(p1);
        }
        if(c0 == c1) {
            if(c0 == 0) {
                cout<<0<<endl;
            } else {
                int ans = mp0.rbegin()->first + mp1.begin()->first;
                cout<<ans / 2;
                if(ans % 2) cout<<".5";
                cout<<endl;
            }
        } else {
            cout<<(c0 > c1 ? mp0.rbegin()->first : mp1.begin()->first)<<endl;
        }
    }
    return 0;
}
