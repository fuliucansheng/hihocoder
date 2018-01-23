#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010, mod = 10007;
struct SegTree{
    int sumA[maxn<<2], sumB[maxn<<2], sumC[maxn<<2], mul[maxn<<2];
    void init(){ memset(sumA, 0, sizeof(sumA)); memset(sumB, 0, sizeof(sumB)); memset(sumC, 0, sizeof(sumC)), memset(mul, 0, sizeof(mul)); }
    void pushup(int node){
        mul[node] = (mul[2*node] * mul[2*node+1]) % mod;
        sumA[node] = (sumA[2*node] * mul[2*node+1] + sumA[2*node+1]) % mod;
        sumB[node] = (mul[2*node] * sumB[2*node+1] + sumB[2*node]) % mod;
        sumC[node] = (sumC[2*node] + sumC[2*node+1] + sumA[2*node] * sumB[2*node+1]) % mod;
    }
    void update(int node, int treeleft, int treeright, int key, int value){
        if(key == treeleft && key == treeright) {
            mul[node] = sumA[node] = sumB[node] = sumC[node] = (value % mod);
            return;
        }
        int treemid = (treeleft + treeright)/2;
        if(key <= treemid) update(2*node, treeleft, treemid, key, value);
        else update(2*node+1, treemid+1, treeright, key, value);
        pushup(node);
    }
} ST;
int main(){
    //freopen("../input.txt","r",stdin);
    int n, q; cin>>n>>q;
    ST.init();
    int l = 0, r = n - 1;
    for(int _=0;_<q;_++){
        int i, x; cin>>i>>x;
        ST.update(1,l,r,i-1,x);
        int rs = ST.sumC[1];
        cout<<(rs >= 0 ? rs : rs + mod)<<endl;
    }
    return 0;
}

