#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    int p = 0, n = int(s.length()), ans = 1, x = 0;
    vector<int> a[26];
    a[s[0] - 'a'].push_back(0);
    for(int i = 1; i < n; i++) {
        int dx = int(s[i] - 'a');
        auto it = lower_bound(a[dx].begin(), a[dx].end(), x);
        if(it == a[dx].end() || *it > p) {
            if(i - p > 1) ans++, p = i - 1;
            if(a[dx].empty()) x = 0, ans++, p = i;
            else x = a[dx].front() + 1;
        } else x = *it + 1;
        if(x > p) p = i, ans++, x = 0;
        a[dx].push_back(i);
    }
    if(p != n - 1) ans++;
    cout<<ans<<endl;
    return 0;
}
