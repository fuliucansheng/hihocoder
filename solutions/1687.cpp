#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 1000010;
struct node{
    ll x, y;
} arr[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n; cin>>n;
    ll rec[n];
    for(ll i=0;i<n;i++) cin>>arr[i].x>>arr[i].y, rec[i] = i;
    sort(rec, rec+n, [arr](int a, int b){ return arr[a].x < arr[b].x; });
    ll s = rec[0], p = rec[1];
    for(ll i=2;i<n;i++){
        ll ne = rec[i];
        if(((arr[p].y-arr[s].y)*(arr[ne].x-arr[s].x)-(arr[p].x-arr[s].x)*arr[ne].y+arr[s].y*(arr[p].x-arr[s].x)) < 0) p = ne;
    }
    cout<<s+1<<" "<<p+1<<endl;
    return 0;
}

