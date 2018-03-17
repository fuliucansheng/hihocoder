#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010, maxm = 1000010;
struct node{
    int s,t,c;
    node(){}
}arr[maxm];
int group[maxn];
bool cmp(node a, node b){ return a.c < b.c; }
int find_group(int x){ return x == group[x] ? x : find_group(group[x]); }
void union_group(int x, int y){
    int dx = find_group(x), dy = find_group(y);
    group[dx] = group[dy] = min(dx, dy);
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n,m,cost = 0;
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>arr[i].s>>arr[i].t>>arr[i].c;
    sort(arr, arr+m, cmp);
    for(int i=1;i<=n;i++) group[i] = i;
    for(int i=0;i<m;i++){
        int ds = find_group(arr[i].s), dt = find_group(arr[i].t);
        if(ds != dt) cost += arr[i].c, union_group(ds, dt);
    }
    cout<<cost<<endl;
    return 0;
}