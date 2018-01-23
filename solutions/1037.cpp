#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    //freopen("../input.txt","r",stdin);
    int n,res = 0;
    cin>>n;
    int store[n+1],num;
    memset(store,0,sizeof(store));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<(n-i);j++){
            cin>>num;
            store[i+j] = num + max(store[i+j],store[i+j+1]);
            if(store[j] > res) res = store[j];
        }
    }
    cout<<res<<endl;
    return 0;
}
