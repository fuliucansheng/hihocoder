#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
long long pm[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}, arr[15];
long long c = 0, ans;
void dfs(int dx, double rs, long long ct){
    double ns = log2(pm[dx+1]);
    for(arr[dx];arr[dx]>0;arr[dx]--){
        arr[dx+1] = int(floor((rs-arr[dx]*log2(pm[dx]))/ns));
        if(arr[dx+1] > 0) dfs(dx+1, rs-arr[dx]*log2(pm[dx]), ct*(arr[dx]+1));
        else{
            long long r = 1;
            for(int k=0;k<=dx;k++) r *= pow(pm[k], arr[k]);
            if(ct*(arr[dx]+1) > c) ans = r, c = ct*(arr[dx]+1);
            if(ct*(arr[dx]+1) == c) ans = min(ans, r);
        }
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(arr, 0, sizeof(arr));
    long long n; cin>>n;
    arr[0] = int(floor(log2(n))), ans = n;
    dfs(0, log2(n), 1);
    cout<<ans<<endl;
    return 0;
}
