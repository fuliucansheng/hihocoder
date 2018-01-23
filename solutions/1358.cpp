#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int maxk = 15;
double arrb[maxk], arra[maxk];
int n, k;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>k;
    for(int i=0;i<k;i++) cin>>arra[i];
    for(int i=0;i<k;i++) cin>>arrb[i], arrb[i] = 1/arrb[i];
    while(n--){
        int dx = 0;
        double dt = 0;
        for(int i=0;i<k;i++){
            double q = pow(arra[i]+1, arrb[i])/pow(arra[i], arrb[i]);
            if(q > dt) dx = i, dt = q;
        }
        arra[dx]++;
    }
    double rs = 1;
    for(int i=0;i<k;i++) rs *= pow(arra[i],arrb[i]);
    cout<<fixed<<setprecision(3)<<rs<<endl;
    return 0;
}

