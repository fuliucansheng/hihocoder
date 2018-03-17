#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int arr[maxn], n;
void solve(){
    int v1[n], v2[n];
    bool s1 = true, s2 = true;
    memset(v1, 0, sizeof(v1));memset(v2, 0, sizeof(v2));
    v1[0] = 1;
    for(int i=0;i<n-1;i++) {
        v1[i+1] = arr[i] - v1[i] - (i > 0 ? v1[i-1] : 0);
        if(!(v1[i+1] == 0 || v1[i+1] == 1)) { s1 = false; break; }
    }
    if(arr[n-1] != v1[n-1] + (n > 1 ? v1[n-2] : 0)) s1 = false;
    for(int i=0;i<n-1;i++) {
        v2[i+1] = arr[i] - v2[i] - (i > 0 ? v2[i-1] : 0);
        if(!(v2[i+1] == 0 || v2[i+1] == 1)) { s2 = false; break; }
    }
    if(arr[n-1] != v2[n-1] + (n > 1 ? v2[n-2] : 0)) s2 = false;
    set<int> m, nm;
    if(!s1&s2) for(int i=0;i<n;i++) v2[i] ? m.insert(i) : nm.insert(i);
    if(!s2&s1) for(int i=0;i<n;i++) v1[i] ? m.insert(i) : nm.insert(i);
    if(s1&s2) for(int i=0;i<n;i++) if(v1[i] == v2[i]) v1[i] ? m.insert(i) : nm.insert(i);
    cout<<m.size();for(auto u:m) cout<<" "<<u+1;cout<<endl;
    cout<<nm.size();for(auto u:nm) cout<<" "<<u+1;cout<<endl;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        solve();
    }
    return 0;
}
