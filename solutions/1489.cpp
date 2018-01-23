#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int p, q, n; cin>>p>>q>>n;
    double rs = 0;
    for(int i=0;i<n;i++){
        double r = 0, c = 1;
        double pp = floor(double(p)/pow(2,i))/100, qq = double(q)/100, pe = 1;
        while(pp < 1){
            r += pe*pp*c;
            pe *= 1 - pp;
            pp += qq;
            c++;
        }
        r += pe*c;
        rs += r;
    }
    cout<<fixed<<setprecision(2)<<rs<<endl;
    return 0;
}
