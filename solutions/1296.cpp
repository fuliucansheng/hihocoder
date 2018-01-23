#include <iostream>
using namespace std;
int g(int n, int k){
    if(n == 1) return 0;
    if(n < k){
        int rs = 0;
        for(int i=2;i<=n;i++) rs = (rs + k)%i;
        return rs;
    }
    int rs = g(n - n/k, k);
    if(rs < n%k) rs = rs - n%k + n;
    else rs = rs - n%k + (rs - n%k)/(k-1);
    return rs;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t, n, k; cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<g(n,k)<<endl;
    }
    return 0;
}
