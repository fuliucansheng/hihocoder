#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    //freopen("../input.txt","r",stdin);
    int k;
    double a;
    cin>>k>>a;
    double beta,data[k],x[k];
    for(int i=0;i<k;i++) cin>>data[i],beta += data[i];
    beta = beta/a;
    for(int i=0;i<k;i++) x[i] = data[i]/beta;
    double res = 0;
    for(int i=0;i<k;i++) res += data[i]*log(x[i]);
    cout<<setiosflags(ios::fixed)<<setprecision(5);
    cout<<res<<endl;
    for(int i=0;i<k;i++) cout<<x[i]<<" ";
    return 0;
}
