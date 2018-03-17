#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct node{
    int x, y, l, id;
}arr[maxn];
double ans[maxn];
int n;
double dfs(int x, int p){
    if(x >= n || arr[x].x >= p) return 0;
    double ret = 0;
    int s = arr[x].x, i = x + 1;
    for(i;i<n;i++) if(arr[i].l < arr[x].l){
        if(arr[i].y < p) {
            ret = max(ans[arr[i].id], ret + double(arr[i].y - s) / arr[x].l);
            s = arr[i].y;
        }else break;
    }
    ret = max(dfs(i, p), ret + double(p - s) / arr[x].l);
    return ret;
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y>>arr[i].l, arr[i].id = i;
    sort(arr, arr + n, [](node a, node b){ return a.x < b.x; });
    for(int i=n-1;i>=0;i--) ans[arr[i].id] = dfs(i, arr[i].y);
    for(int i=0;i<n;i++) cout<<fixed<<setprecision(2)<<ans[i]<<endl;
    return 0;
}