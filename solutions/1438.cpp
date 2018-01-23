#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
#define d(i) (double(rec[i])/(ans[i]+1))
const int maxn = 1010;
int arr[maxn], rec[maxn], ans[maxn], m, n, k;
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(ans, 0, sizeof(ans));
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n == 2) return cout<<fixed<<setprecision(1)<<double(arr[1]-arr[0])/(k+1)<<endl, 0;
    for(int i=1;i<n;i++) rec[i-1] = arr[i] - arr[i-1];
    while(k > 0){
        int df = (d(0) > d(1) ? 0 : 1), ds = 1 - df;
        double sf = d(df), ss = d(ds);
        for(int j=2;j<n-1;j++)
            if(d(j) >= sf) ss = sf, ds = df, df = j, sf = d(j);
            else if(d(j) >= ss) ss = d(j), ds = j;
        int dx = max(int(ceil(rec[df]/ss)) - 1 - ans[df], 1);
        ans[df] = ans[df] + min(dx, k), k -= dx;
    }
    double rs = 0;
    for(int i=0;i<n-1;i++) rs = max(rs, d(i));
    cout<<fixed<<setprecision(1)<<rs<<endl;
    return 0;
}
