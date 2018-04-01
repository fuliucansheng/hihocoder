#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char dfs(ll k, int x = 100){
    if(x == 1 || k == 0) return 'h';
    if(k & 1){
        char c = dfs(k / 2, x - 1);
        if(c == 'h') return 'i';
        if(c == 'i') return 'o';
        if(c == 'o') return 'h';
    }
    return dfs(k / 2, x - 1);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        ll k; cin>>k;
        cout<<dfs(k - 1)<<endl;
    }
    return 0;
}
