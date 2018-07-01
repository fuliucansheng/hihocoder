#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    string a, b; cin>>a>>b;
    a = '0' + a, b = '0' + b;
    string aa(n, '0'), bb(n, '0');
    for(int i = 1; i <= n; i++) aa[i - 1] = a[i] != a[i - 1];
    for(int i = 1; i <= n; i++) bb[i - 1] = b[i] != b[i - 1];
    int ans = 0;
    for(int i = 0; i < n; i++) if(aa[i] != bb[i]) ans++;
    cout<<(ans + 1) / 2<<endl;
    return 0;
}
