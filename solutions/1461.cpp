#include <bits/stdc++.h>
using namespace std;
bool solve(int a, int b){
    int ans[80], nn = 0;
    while(max(a,b) != 1 || min(a,b) != 0){
        ans[nn++] = (a >= b ? 0 : 1);
        if(nn >= 60) return false;
        if(a >= b) a -= b; else b -= a;
        if(min(a, b) == 0 && max(a, b) != 1) return false;
    }
    if(a == 1 && b == 0) for(int i=0;i<nn;i++) ans[i] ^= 1;
    for(int i=nn-1;i>=0;i--) cout<<ans[i]; cout<<endl;
    return true;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        double c = (sqrt(5) - 1) / 2;
        for(int i=max(1, int(n*c)-50);i<n;i++) if(solve(n, i)) break;
    }
}
