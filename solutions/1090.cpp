#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1050;
struct car{
    int x,y,l,i;
}arr[maxn];
int n;
double t[maxn];
double dfs(int c, double p){
    if(c>=n || p <= arr[c].x) return 0;
    double x = arr[c].x, tt = 0;
    int i;
    for(i=c+1;i<n;i++){
        if(arr[i].l < arr[c].l){
            if(arr[i].y < p){
                tt = max(t[arr[i].i], tt+(arr[i].y-x)/arr[c].l);
                x = arr[i].y;
            } else break;
        }
    }
    double ft = dfs(i, p);
    tt = max(ft, tt+(p-x)/arr[c].l);
    return tt;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(t, 0, sizeof(t));
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y>>arr[i].l, arr[i].i = i;
    sort(arr, arr+n, [](car a, car b){ return a.x<b.x;});
    for(int i=n-1;i>=0;i--) t[arr[i].i] = dfs(i, arr[i].y);
    for(int i=0;i<n;i++) cout<<fixed<<setprecision(2)<<t[i]<<endl;
    return 0;
}
