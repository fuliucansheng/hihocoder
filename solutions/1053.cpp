#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 100010;
pii arr[maxn];
int rc[maxn], n, R;
bool is_valid(int m){
    memset(rc, 0, sizeof(rc));
    int p = 0;
    for(int i=0;i<n;i++){
        while(abs(arr[i].first - arr[p].first) > R) p++;
        int c = arr[i].second;
        while(c) {
            if(p >= n || abs(arr[i].first - arr[p].first) > R) return false;
            int d = min(c, m - rc[p]);
            rc[p] += d, c -= d;
            if(rc[p] == m) p++;
        }
    }
    return true;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        cin>>n>>R;
        for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
        sort(arr, arr + n);
        int l = 0, r = 1000000000;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(is_valid(m)) r = m; else l = m;
        }
        if(is_valid(l)) cout<<l<<endl;
        else cout<<r<<endl;
    }
    return 0;
}

