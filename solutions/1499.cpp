#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010;
ll arr[2][maxn], sum = 0, n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(ll j=0;j<n;j++) for(ll i=0;i<2;i++) cin>>arr[i][j], sum += arr[i][j];
    ll ave = sum / (2 * n);
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll d0 = arr[0][i] - ave, d1 = arr[1][i] - ave;
        if(d0 >= 0 && d1 >= 0) ans += d0 + d1, arr[0][i+1] += d0, arr[1][i+1] += d1;
        else if(d0 >= 0 && d1 <= 0){
            if(d0 + d1 > 0) ans += d0, arr[0][i+1] += d0 + d1;
            else ans += abs(d1), arr[1][i+1] += d0 + d1;
        }else if(d0 <= 0 && d1 >= 0){
            if(d0 + d1 > 0) ans += d1, arr[1][i+1] += d0 + d1;
            else ans += abs(d0), arr[0][i+1] += d0 + d1;
        }else ans += abs(d0 + d1), arr[0][i+1] += d0, arr[1][i+1] += d1;
    }
    cout<<ans<<endl;
    return 0;
}
