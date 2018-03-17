#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
unordered_map<string,int> dict;
string arr[maxn];
vector<int> graph[maxn];
struct SparseTableRMQ{
    int arr[maxn<<1][20], n;
    void build(){
        int l = int(log2(n));
        for(int j=1;j<=l;j++)
            for(int i=1;(i+(1<<(j-1))-1)<=n;i++)
                arr[i][j] = min(arr[i][j-1],arr[i+(1<<(j-1))][j-1]);
    }
    int query(int l, int r){
        int k=int(log2(r-l+1));
        return min(arr[l][k],arr[r-(1<<k)+1][k]);
    }
} ST;
int rc[maxn], irc[maxn<<1], cnt = 1, n, m;
void dfs(int u){
    rc[u] = ST.n, irc[rc[u]] = u;
    ST.arr[ST.n++][0] = rc[u];
    for(auto v:graph[u]) dfs(v), ST.arr[ST.n++][0] = rc[u];
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        string uu, vv; cin>>uu>>vv;
        if(!dict.count(uu)) dict[uu] = cnt, arr[cnt++] = uu;
        if(!dict.count(vv)) dict[vv] = cnt, arr[cnt++] = vv;
        int u = dict[uu], v = dict[vv];
        graph[u].push_back(v);
    }
    ST.n = 1, dfs(1);
    ST.build();
    cin>>m;
    for(int i=0;i<m;i++){
        string uu, vv; cin>>uu>>vv;
        int u = dict[uu], v = dict[vv];
        int ans = ST.query(min(rc[u], rc[v]), max(rc[u], rc[v]));
        cout<<arr[irc[ans]]<<endl;
    }
    return 0;
}