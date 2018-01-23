#include <iostream>
using namespace std;
const int mod = 19999997;

int main(){
    //freopen("../input.txt","r",stdin);
    int n, a = 1, b = 2, r;
    cin>>n;
    if(n == 1) cout<<a<<endl;
    else if(n == 2) cout<<b<<endl;
    else{
        for(int i=0;i<n-2;i++){
            r = a + b;
            r %= mod;
            a = b;
            b = r;
        }
        cout<<(r%mod)<<endl;
    }
    return 0;
}
