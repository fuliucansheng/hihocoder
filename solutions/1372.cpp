#include <iostream>
#include <cmath>
using namespace std;
bool g1(int n){
    return int(sqrt(n)) == sqrt(n);
}
bool g2(int n){
    double lmt = sqrt(n);
    for(int i=1;i<=lmt;i++) if(g1(n-i*i)) return true;
    return false;
}
bool g3(int n){
    double lmt = sqrt(n);
    for(int i=1;i<=lmt;i++) if(g2(n-i*i)) return true;
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int n;
    while(cin>>n){
        if(n == -1) break;
        if(g1(n)) cout<<1<<endl;
        else if(g2(n)) cout<<2<<endl;
        else if(g3(n)) cout<<3<<endl;
        else cout<<4<<endl;
    }
    return 0;
}

