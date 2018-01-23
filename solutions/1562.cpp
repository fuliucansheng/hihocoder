#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int t,h,m,s,T;
    cin>>T;
    while(T--){
        cin>>h>>m>>s>>t;
        s += t;m += s/60, s %= 60;
        h += m/60, m %= 60; h %= 24;
        double hd = (h >= 12 ? h - 12 : h) * 30 + (m * 60 + s)/double(3600)*30;
        double md = m * 6 + s / double(60) * 6;
        cout<<fixed<<setprecision(4)<<min(abs(hd-md), abs(360-abs(hd-md)))<<endl;
    }
    return 0;
}
