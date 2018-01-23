#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e6+50;
int vis[maxn], stk[maxn], n, sk = 0;
int main(){
    //freopen("../input.txt","r",stdin);
    memset(vis, 0 , sizeof(vis));memset(stk, 0 , sizeof(stk));
    for(int i=2;i<maxn;i++){
        if(vis[i] == 0) {
            stk[sk++] = i;
            for(int j=1;i*j<maxn;j++) vis[i*j] = 1;
        }
    }
    cin>>n;
    int l = 0, r = sk-1;
    while(l < r){
        if(stk[l]+stk[r] == n) break;
        if(stk[l]+stk[r] > n) r--; else l++;
    }
    cout<<stk[l]<<" "<<stk[r]<<endl;
    return 0;
}
