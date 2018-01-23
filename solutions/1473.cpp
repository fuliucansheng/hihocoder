#include <iostream>
using namespace std;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        int l,f,d; cin>>l>>f>>d;
        int r = gcd(l , d%l);
        if(r >= f) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    return 0;
}
