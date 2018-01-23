#include <iostream>
#include <cmath>
using namespace std;
#define d(u,v) sqrt(pow(u.first-v.first,2)+pow(u.second-v.second,2))
typedef pair<double,double> ps;
const double eps = 1e-6;
double g(ps a, ps b, ps c){
    double dab = d(a,b), dac = d(a,c), dbc = d(b,c);
    double s = (dab+dac+dbc)/2;
    return sqrt(s*(s-dab)*(s-dac)*(s-dbc));
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        ps p,a,b,c;
        cin>>p.first>>p.second>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
        bool s = ((g(p,a,b)+g(p,a,c)+g(p,b,c)-g(a,b,c))/g(a,b,c) < eps);
        cout<<(s ? "YES" : "NO")<<endl;
    }
    return 0;
}
