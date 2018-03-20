#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 100010;
struct SparseTableRMQ{
    int arr[maxn][20], n;
    void build(){
        int l = int(log2(n));
        for(int j=1;j<=l;j++)
            for(int i=1;(i+(1<<(j-1))-1)<=n;i++)
                arr[i][j] = max(arr[i][j-1],arr[i+(1<<(j-1))][j-1]);
    }
    int query(int l, int r){
        int k=int(log2(r-l+1));
        return max(arr[l][k],arr[r-(1<<k)+1][k]);
    }
} ST;
int arr[maxn], fa[maxn], n, m;
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m;
    vector<pii> vec;
    for(int i=0;i<n;i++) cin>>arr[i];
    int d = arr[1] - arr[0], p = 0;
    for(int i=1;i<n;i++) if(arr[i] - arr[i-1] != d) vec.push_back(pii(p + 1, i)), p = i - 1, d = arr[i] - arr[i-1];
    vec.push_back(pii(p + 1, n));
    p = 0;
    for(int i=1;i<=n;i++) {
        if(vec[p].second <= i && p + 1 < int(vec.size())) p++;
        if(vec[p].first <= i && vec[p].second >= i) ST.arr[i][0] = vec[p].second - i + 1, fa[i] = vec[p].first;
    }
    ST.n = n, ST.build();
    for(int i=0;i<m;i++){
        int l, r, ans = 0; cin>>l>>r;
        if(fa[r] - 1 >= l) ans = max(ans, ST.query(l, fa[r] - 1));
        cout<<max(ans, r - max(l, fa[r]) + 1)<<endl;
    }
    return 0;
}
