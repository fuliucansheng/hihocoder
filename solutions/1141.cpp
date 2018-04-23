#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100050;
int arr[maxn];
ll dfs(int l, int r){
    if(l == r) return 0;
    int m = (l + r)>>1;
    ll rl = dfs(l, m), rr = dfs(m+1, r), rs = 0;
    vector<int> tp;
    int a = l, b = m + 1;
    while(a <= m || b <= r){
        if(a <= m && b <= r){
            if(arr[a] > arr[b]) tp.push_back(arr[b++]);
            else tp.push_back(arr[a++]), rs += (ll)b - m - 1;
        }else if(a <= m) rs += (ll)r - m, tp.push_back(arr[a++]);
        else if(b <= r) tp.push_back(arr[b++]);
    }
    for(int i = l; i <= r; i++) arr[i] = tp[i - l];
    return rs + rl + rr;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    cout<<dfs(0, n-1)<<endl;
    return 0;
}
