#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int arr[maxn], rc[maxn], pre[maxn], n, y, len;
ll k;
bool is_valid(int m){ // >= m的个数>=k true
    ll cnt = 0;
    memset(rc, 0, sizeof(rc)); memset(pre, 0, sizeof(pre));
    vector<int> mst[maxn]; mst[0].push_back(0);
    for(int i=1;i<=n;i++) {
        rc[i] = (arr[i] >= m ? len - y : -y), pre[i] = pre[i-1] + rc[i];
        int idx = i % len;
        auto p = upper_bound(mst[idx].begin(), mst[idx].end(), pre[i]);
        cnt += ll(p - mst[idx].begin());
        mst[idx].insert(p, pre[i]);
    }
    return cnt >= k;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>len>>y>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int l = 0, r = maxn;
    while(r - l > 1){
        int m = (l + r) / 2;
        if(is_valid(m)) l = m; else r = m;
    }
    cout<<(is_valid(r) ? r: l)<<endl;
    return 0;
}
