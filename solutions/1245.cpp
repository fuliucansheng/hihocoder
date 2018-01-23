#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        double a, b, c, l;
        cin>>a>>b>>c>>l;
        double s = 0.5*(a+b+c+l);
        double aa = min(a, min(b,c)), cc = max(a, max(b,c));
        double bb = a + b + c - aa - cc, ll = l, rs;
        if(bb - aa >= ll) aa += ll;
        else if((cc - aa) + (cc - bb) >= ll) aa = bb = 0.5*(2*s - cc);
        else aa = bb = cc = 2*s/3;
        rs = sqrt(s*(s-aa)*(s-bb)*(s-cc));
        cout<<fixed<<setprecision(10)<<rs<<endl;
    }
    return 0;
}
