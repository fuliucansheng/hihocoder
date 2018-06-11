#include <bits/stdc++.h>
using namespace std;
int a[2010];
int main() {
    //freopen("../input.txt", "r", stdin);
    int n, t; cin>>n>>t;
    int nn = (1 << n);
    for(int i = 0; i < nn; i++) cin>>a[i];
    if(t % 2 == 0) for(int i = 0; i < nn; i++) cout<<a[i]<<endl;
    else for(int i = nn - 1; i >= 0; i--) cout<<a[i]<<endl;
    return 0;
}
