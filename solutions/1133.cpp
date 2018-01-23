#include <iostream>
using namespace std;
const long long maxn = 1e6+10;
long long n, k, arr[maxn];
long long find(long long l, long long r){
    long long st = arr[l], ll = l+1, rr = r, p = l;
    while(ll <= rr){
        if(arr[ll] < st) arr[p++] = arr[ll++];
        else if(arr[rr] < st) arr[p++] = arr[rr], arr[rr--] = arr[ll++];
        else rr--;
    }
    arr[p] = st;
    if(p == k) return arr[k];
    return p > k ? find(l,p-1) : find(p+1,r);
}
int main(){
    //freopen("../input.txt","r",stdin);
    scanf("%lld%lld", &n, &k);k--;
    for(long long i=0;i<n;i++) scanf("%lld", &arr[i]);
    if(k > n) cout<<-1<<endl;
    else cout<<find(0, n-1)<<endl;
    return 0;
}
