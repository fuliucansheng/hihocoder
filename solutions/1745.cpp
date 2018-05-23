#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
    //freopen("../input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    vector<int> a(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int ans = 0, sz = int(a.size());
    for(int i = 0; i < sz; i++) {
        int e = a[i] + k - 1;
        int dx = int(lower_bound(a.begin() + i, a.end(), e) - a.begin());
        if(dx == sz || a[dx] > e) dx--;
        if(dx - i + 1 >= k - m) ans = e;
    }
    cout<<ans<<endl;
    return 0;
}
