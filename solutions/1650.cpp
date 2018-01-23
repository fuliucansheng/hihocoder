#include <iostream>
using namespace std;
long long n, l;
bool is_valid(long long m){
    long long s = 1, mm = m, r = 1;
    for(long long i=1;i<l && mm > 0;i++){
        if(s >= n || ((n-s)/r < mm)) return true;
        r *= mm--;
        s += r;
    }
    if(s < n) return false;
    return true;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>l;
    long long sl = 1, sr = n;
    while(sr - sl > 1){
        long long sm = (sl + sr)/2;
        if(is_valid(sm)) sr = sm; else sl = sm;
    }
    if(is_valid(sl)) cout<<sl<<endl; else cout<<sr<<endl;
    return 0;
}
