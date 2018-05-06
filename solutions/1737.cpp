#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    int n = int(s.length());
    vector<int> rc[26];
    for(int i = 0; i < n; i++) rc[s[i] - 'a'].push_back(i);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        int dx = int(lower_bound(rc[x].begin(), rc[x].end(), i) - rc[x].begin());
        int lcc = dx > 0 ? rc[x][dx - 1] + 1 : 0, rcc = dx + 1 < int(rc[x].size()) ? rc[x][dx + 1] - 1 : n - 1;
        ans += ll(i - lcc + 1) * ll(rcc - i + 1);
    }
    cout<<ans<<endl;
    return 0;
}
