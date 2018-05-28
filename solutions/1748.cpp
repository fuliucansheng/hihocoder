#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn], v[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    int n, m; scanf("%d%d", &n, &m);
    memset(v, 0, sizeof(v));
    for(int i = 0; i < m; i++) scanf("%d", &a[i]), v[a[i]] = 1;
    int p = 0, x = 1;
    for(int i = 0; i < n; i++) {
        while(v[x]) x++;
        if(p == m || (x < n && x < a[p])) printf("%d\n", x++);
        else printf("%d\n", a[p++]);
    }
    return 0;
}
