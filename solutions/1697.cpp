#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int idr[maxn], pre[maxn], n, c = 0;
void dfs(int l, int r){
    int dx = -1, mn = INT32_MAX;
    for(int i=l;i<=r;i++) if(idr[i] < mn) dx = i, mn = idr[i];
    pre[c++] = mn;
    if(dx > l) dfs(l, dx - 1);
    if(dx < r) dfs(dx + 1, r);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>idr[i];
    dfs(0, n-1);
    for(int i=0;i<n;i++) cout<<pre[i]<<endl;
    return 0;
}
