#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn], n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    int l = 0, r = n - 1;
    while(l + 1 < n && a[l + 1] >= a[l]) l++;
    while(r > 0 && a[r - 1] <= a[r]) r--;
    if(l == n - 1 || r == 0) return cout<<0<<endl, 0;
    int ans = r;
    for(int i = 0; i <= l; i++) {
        int dx = int(lower_bound(a + r, a + n, a[i]) - a);
        ans = min(ans, dx - i - 1);
    }
    cout<<ans<<endl;
    return 0;
}
