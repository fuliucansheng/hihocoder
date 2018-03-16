#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int m,n,d,v;
    cin>>n>>m;
    int rec[m+1];
    memset(rec, 0, sizeof(rec));
    for(int i=0;i<n;i++){
        cin>>d>>v;
        for(int j=d;j<=m;j++) rec[j] = max(rec[j-d]+v,rec[j]);
    }
    cout<<rec[m]<<endl;
    return 0;
}