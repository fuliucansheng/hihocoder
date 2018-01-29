#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
bool vis[maxn];
int main() {
    //freopen("../input.txt", "r" , stdin);
    int n, ans = INT32_MAX; cin>>n;
    string a, b; cin>>a>>b;
    int p[n];
    for(int i=0;i<n;i++) p[i] = i;
    do{
        memset(vis, 0, sizeof(vis));
        int r = 0;
        for(int i=0;i<n;i++) if(!vis[i]){
                int x = i, m = 0;
                while(!vis[x]) vis[x] = 1, x = p[x], m++;
                r += m - 1;
            }
        for(int i=0;i<n;i++){
            int aa = a[p[i]] - '0', bb = b[i] - '0';
            r += min(abs(aa - bb), 10 - abs(aa - bb));
        }
        ans = min(ans, r);
    }while(next_permutation(p, p + n));
    cout<<ans<<endl;
    return 0;
}
