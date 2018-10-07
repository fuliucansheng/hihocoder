#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii aa[6], a[6];
int dx[6], p[6];
bool is_valid() {
    for(int i = 0; i < 2; i++) {
        bool ret = true;
        p[2] = a[0].first, p[3] = a[0].second;
        if(i == 1) swap(p[2], p[3]);
        if(a[1].first != p[2] && a[1].second != p[2]) ret = false;
        if(a[2].first != p[3] && a[2].second != p[3]) ret = false;
        if(min(a[4].first, a[4].second) != min(p[2], p[3]) || max(a[4].first, a[4].second) != max(p[2], p[3])) return false;
        p[1] = (a[1].first == p[2] ? a[1].second : a[1].first);
        p[4] = (a[2].first == p[3] ? a[2].second : a[2].first);
        if(a[3].first != p[1] && a[3].second != p[1]) ret = false;
        if(a[5].first != p[4] && a[5].second != p[4]) ret = false;
        if(ret) return true;
    }
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--) {
        for(int i = 0; i < 6; i++) {
            cin>>aa[i].first>>aa[i].second;
            dx[i] = i;
        }
        bool status = false;
        do {
            for(int i = 0; i < 6; i++) a[i] = aa[dx[i]];
            status = is_valid();
            if(status) break;
        } while(next_permutation(dx, dx + 6));
        cout<<(status ? "YES" : "NO")<<endl;
    }
    return 0;
}
