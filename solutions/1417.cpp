#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int rec[32], n, k;
void update(int m){
    int b = 0;
    while(m){
        if(m&1) rec[b]++;
        m >>= 1, b++;
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(rec, 0, sizeof(rec));
    cin>>n;
    for(int i=0;i<n;i++) cin>>k, update(k);
    ll rs = 0;
    for(int i=0;i<32;i++) rs += ll(rec[i])*(n-rec[i]);
    cout<<rs<<endl;
    return 0;
}
