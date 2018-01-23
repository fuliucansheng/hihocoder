#include <iostream>
using namespace std;
int dfs(int i, int c, double p, int n, double price[], int eager[]){
    if(c == 0 || i == n) {
        if((p - int(p)) == 0 && int(p)%5 == 0) return 0;
        return -INT32_MAX;
    }
    int chose = dfs(i+1, c-1, p+price[i], n, price, eager);
    int no_chose = dfs(i+1, c, p, n, price, eager);
    return max(chose+eager[i], no_chose);
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int eager[n], c = 3;
        double price[n], p = 0;
        for(int i=0;i<n;i++) cin>>price[i]>>eager[i];
        cout<<dfs(0,c,p,n,price,eager)<<endl;
    }
    return 0;
}
