#include <iostream>
#include <cmath>
using namespace std;
long long sub(long long a, long long b){
    if(b == 0) return a;
    else return sub(b, a%b);
}
long long get(long long k){
    double lmt = sqrt(k);
    long long rs = 0;
    for(long long i=1;i<=lmt;i++) if(k%i == 0) rs += (i == lmt ? 1 : 2);
    return rs;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    long long m, n; cin>>n>>m;
    long long c = sub(max(m,n), min(m,n));
    long long sm = get(m), sc = get(c), sn = get(n);
    long long mc = sub(max(sm, sc), min(sm, sc));
    sm /= mc, sc /= mc;
    long long nc = sub(max(sn, sc), min(sn, sc));
    sn /= nc, sc /= nc;
    cout<<(sm*sn)<<" "<<sc<<endl;
    return 0;
}
