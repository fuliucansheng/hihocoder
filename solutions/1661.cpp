#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100010;
ll arr[maxn], rc[maxn], n, k;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>k;
    memset(rc, 0, sizeof(rc));
    ll ans = 0;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        priority_queue<ll,vector<ll>,greater<ll>> Q;
        ll sum = 0;
        for(int j=i;j<n;j++){
            if(Q.size() < k) Q.push(arr[j]), sum += arr[j];
            else if(Q.top() < arr[j]) {
                if(Q.top() == arr[i]) { rc[j]++; break; }
                sum = sum - Q.top() + arr[j], Q.pop(), Q.push(arr[j]);
            }
            ans += sum;
            if(Q.size() == k && rc[j]) ans += rc[j] * sum, rc[j+1] += rc[j], rc[j] = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
