#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> graph[maxn];
struct SparseTableRMQ{
    int arr[maxn<<1][20], n;
    void build(){
        int l = int(log2(n));
        for(int j = 1; j <= l; j++)
            for(int i = 1;(i + (1 << (j - 1)) - 1) <= n; i++)
                arr[i][j] = min(arr[i][j - 1],arr[i + (1<<(j - 1))][j - 1]);
    }
    int query(int l, int r){
        int k = int(log2(r - l + 1));
        return min(arr[l][k], arr[r - (1 << k) + 1][k]);
    }
} ST;
int rc[maxn], irc[maxn<<1], ht[maxn], n, q;
void dfs(int u){
    rc[u] = ST.n, irc[rc[u]] = u;
    ST.arr[ST.n++][0] = rc[u];
    for(auto v: graph[u]) {
        ht[v] = ht[u] + 1;
        dfs(v), ST.arr[ST.n++][0] = rc[u];
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>q;
    for(int i = 2, x; i <= n; i++) cin>>x, graph[x].push_back(i);
    ST.n = 1, ht[1] = 1, dfs(1);
    ST.build();
    while(q--) {
        int k, mn = -1, mx = -1; cin>>k;
        for(int i = 0, x; i < k; i++) {
            cin>>x;
            if(mn == -1 || mn > rc[x]) mn = rc[x];
            if(mx == -1 || mx < rc[x]) mx = rc[x];
        }
        int rt = irc[ST.query(mn, mx)];
        cout<<ht[rt]<<endl;
    }
    return 0;
}
