#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int tax, i = 0;
    cin>>tax;
    int base[] = {1500, 4500, 9000, 35000, 55000, 80000},taxb[] = {45, 345, 1245, 7745, 13745, 22495};
    double taxr[] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
    while(i < 6 && taxb[i] < tax) i++;
    if(i == 0) cout<<3500+int(tax/taxr[0])<<endl;
    else cout<<3500+int((tax - taxb[i-1])/taxr[i] + base[i-1])<<endl;
    return 0;
}
