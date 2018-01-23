#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
    int l, r, id;
    bool operator < (const node &x) const {
        return r == x.r ? l < x.l : r < x.r;
    }
} qry[maxn];
vector<int> graph[maxn];
int rec[maxn], ans[maxn], n, q;
int lowbit(int x){ return x&-x; }
void add(int x, int v){
    while(x <= n){
        rec[x] += v;
        x += lowbit(x);
    }
}
int query(int x){
    int rs = 0;
    while(x){
        rs += rec[x];
        x -= lowbit(x);
    }
    return rs;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(rec, 0, sizeof(rec)); memset(ans, 0, sizeof(ans));
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b), graph[b].push_back(a);
    }
    for(int i=0;i<q;i++) cin>>qry[i].l>>qry[i].r, qry[i].id = i;
    sort(qry, qry + q);
    int qq = 0;
    for(int i=1;i<=n;i++){
        for(auto v:graph[i]) if(v < i) add(v, 1);
        while(qq < q && i == qry[qq].r)
            ans[qry[qq].id] = qry[qq].r - qry[qq].l + 1 - (query(qry[qq].r) - query(qry[qq].l - 1)), qq++;
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<endl;
    return 0;
}
