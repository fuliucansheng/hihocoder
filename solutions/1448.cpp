#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int arr[maxn], rec[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        int n, k, m; cin>>n>>k;
        memset(arr, 0, sizeof(arr)); memset(rec, 0, sizeof(rec));
        bool rs = true;
        for(int i=0;i<n;i++) cin>>m, arr[m]++;
        ll c = 0;
        for(int i=0;i<k-1;i++)
            if(arr[i] < c) { rs = false; break; }
            else rec[i] = arr[i] - int(c), c += ll(rec[i]);
        for(int i=k-1;i<maxn;i++)
            if(arr[i] < c) { rs = false; break; }
            else rec[i] = arr[i] - int(c), c -= ll(rec[i-k+1]), c += rec[i];
        for(int i=maxn-k+1;i<maxn;i++) if(rec[i]) { rs = false; break; }
        cout<<(rs ? "YES" : "NO")<<endl;
    }
    return 0;
}
