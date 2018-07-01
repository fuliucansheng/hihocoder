#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct node{
    int a, b, c;
} a[maxn];
int x[3];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; scanf("%d", &n);
    int mx0 = 0, mx1 = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &x[0], &x[1], &x[2]);
        sort(x, x + 3);
        a[i].a = x[0], a[i].b = x[1], a[i].c = x[2];
        mx0 = max(mx0, x[0]), mx1 = max(mx1, x[1]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int aa = a[i].a, bb = a[i].b, cc = a[i].c;
        if(cc > mx1 && bb > mx0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
