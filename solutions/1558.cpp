#include <iostream>
#include <cstring>
using namespace std;
int n,k,stk[10];
void dfs(int m, int h){
    if(h == 0) {
        for(int i=1;i<=n;i++) cout<<stk[i];
        cout<<endl;
        return;
    }
    for(int i=0;i<=k;i++) {
        if(stk[0] == 0 && i ==0 ) continue;
        if(m*i <= k) stk[++stk[0]] = i, dfs(i, h-1);
        else break;
        stk[0]--;
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(stk, 0, sizeof(stk));
    cin>>n>>k;
    dfs(1,n);
    return 0;
}
