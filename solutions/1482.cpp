#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 100010, mod = 1e9+7;
ll arr[maxn], rec[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    arr[1] = 2, rec[1] = 1, arr[2] = 4, rec[2] = 4, arr[3] = 7, rec[3] = 12, arr[4] = 13, rec[4] = 30;
    for(int i=5;i<=n;i++){
        arr[i] = 2*arr[i-1] - arr[i-4], arr[i] %= mod;
        rec[i] = arr[i-1] + 2*rec[i-1] - rec[i-4] - arr[i-4], rec[i] %= mod;
    }
    ll rs = (arr[n]+rec[n])%mod;
    cout<<(rs < 0 ? rs + mod : rs)<<endl;
    return 0;
}
