#include <iostream>
using namespace std;
const int N = 1000000007;
int main() {
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    int z=1,nz=1,t,s=2;
    for(int i=1;i<n;i++){
        t = z;
        z = nz + z;
        nz = t;
        s *= 2;
        s %= N,z %= N,nz %= N;
    }
    int r = (z+nz)%N;
    cout<<((s-r)<0?(s-r)+N:(s-r))<<endl;
    return 0;
}
