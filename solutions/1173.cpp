#include <iostream>
using namespace std;
int sg(int x){
    if(x == 0) return 0;
    else if(x % 4 == 0) return x - 1;
    else if(x % 4 == 3) return x + 1;
    else return x;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int s = 0, n, x; cin>>n;
    for(int i=0;i<n;i++) cin>>x, s ^= sg(x);
    if(s == 0) cout<<"Bob"<<endl; else cout<<"Alice"<<endl;
    return 0;
}
