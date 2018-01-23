#include <iostream>
using namespace std;
const long long maxn = 1010, mod = 1000000007;
long long m, n, k, rec[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m>>k;
    rec[1] = m;
    for(int i=2;i<k;i++) rec[i] = rec[i-1]*m, rec[i] %= mod;
    rec[k] = rec[k-1]*m - m; rec[k] %= mod;
    for(int i=k+1;i<=n;i++) rec[i] = m*rec[i-1] - rec[i-k]*(m-1), rec[i] %= mod;
    cout<<(rec[n] > 0 ? rec[n] : rec[n] + mod)<<endl;
    return 0;
}
