#include <iostream>
using namespace std;
int dfs(int i, int n){
    if(i == 0) return 0;
    int ni = i/4, it = i%4;
    if(it == 1 || it == 2) return n;
    return dfs(ni, n-1);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t, i, n; cin>>t;
    while(t--){
        cin>>i>>n;
        cout<<dfs(i-1,n)<<endl;
    }
    return 0;
}
