#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    int ds[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>ds[i][j];
    int rs = n*(n-1)/2;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=0;k<n;k++){
                if(i == k || k == j) continue;
                if(ds[i][j] == (ds[i][k] + ds[k][j])){
                    rs--;
                    break;
                }
            }
    cout<<rs<<endl;
    return 0;
}
