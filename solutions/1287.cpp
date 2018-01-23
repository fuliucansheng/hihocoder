#include <iostream>
using namespace std;
long long mm(long long a, long long b, long long k){
    long long rs = 0;
    a %= k, b %= k;
    while(b){
        if(b&1) rs += a, rs %= k;
        a <<= 1, a %= k, b >>= 1;
    }
    return rs >= 0 ? rs : rs + k;
}
long long pwm(long long a, long long u, long long k){
    long long rs = 1;
    while(u){
        if(u&1) rs = mm(rs, a, k);
        a = mm(a, a, k), u >>= 1;
    }
    return rs >= 0 ? rs : rs + k;
}
bool mr(long long k){
    if(k <= 2) return k == 2;
    if(k % 2 == 0) return false;
    long long u = k - 1;
    while(u % 2 == 0) u /= 2;
    for(int i=0;i<20;i++){
        long long a = rand()%(k - 2) + 2;
        long long x = pwm(a, u, k);
        while(u < k){
            long long y = mm(x, x, k);
            if(y == 1 && x != 1 && x != k - 1) return false;
            x = y; u *= 2;
        }
        if(x != 1) return false;
    }
    return true;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        cout<<(mr(n) ? "Yes" : "No")<<endl;
    }
    return 0;
}
