#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    int rr = 0, re = 0, er = 0, ee = 0;
    char a, b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a == '+'){
            if(b == '+') rr++;
            else er++;
        }else{
            if(b == '+') re++;
            else ee++;
        }
    }
    double p = rr/double((rr+er) == 0 ? 1 : (rr+er)),r = rr/double((rr+re) == 0 ? 1 : (rr+re));
    double res = 2*p*r/((p+r) == 0 ? 1 : (p+r));
    char rs[20];
    sprintf(rs,"%.2f",res*100);
    cout<<rs<<"%"<<endl;
    return 0;
}
