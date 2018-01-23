#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100010;
int tb[maxn][32], arr[maxn];
void rmq_init(){
    for(int i=1;i<maxn;i++) tb[i][0] = arr[i];
    for(int j=1;(1<<j)<=maxn;j++) for(int i=1;i+(1<<(j-1))<=maxn;i++) tb[i][j] = max(tb[i][j-1], tb[i+(1<<(j-1))][j-1]);
}
int rmq_query(int l, int r){
    int k = 0;
    while((1<<(k+1)) <= (r-l+1)) k++;
    return max(tb[l][k], tb[r-(1<<k)+1][k]);
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(arr, 0, sizeof(arr)); memset(tb, 0, sizeof(tb));
    int m, n; cin>>n>>m;
    for(int i=0;i<n;i++){
        int t, v; cin>>t>>v;
        arr[t] = max(arr[t], v);
    }
    rmq_init();
    for(int i=0;i<m;i++){
        int a, b; cin>>a>>b;
        int r = rmq_query(a, b);
        if(r == 0) cout<<"None"<<endl; else cout<<r<<endl;
    }
    return 0;
}
