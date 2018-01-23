#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 300010;
struct SplayTree{
    int size[maxn], pre[maxn], rev[maxn], val[maxn], ch[maxn][2], tot, root;
    void init(int n){
        memset(size, 0, sizeof(size)); memset(pre, 0, sizeof(pre)); memset(rev, 0, sizeof(rev));
        memset(ch, 0, sizeof(ch)); tot = n;
        build(root, 1, n, 0);
        pushup(root);
    }
    void dfs(int ne){
        if(!ne) return;
        pushdown(ne);
        if(ch[ne][0]) pushdown(ch[ne][0]), dfs(ch[ne][0]);
        if(val[ne] != 1000) cout<<char(val[ne]);
        if(ch[ne][1]) pushdown(ch[ne][0]), dfs(ch[ne][1]);
    }
    void pushup(int ne){ size[ne] = size[ch[ne][0]] + size[ch[ne][1]] + 1; }
    void pushdown(int ne){ if(rev[ne]) swap(ch[ne][0], ch[ne][1]), rev[ch[ne][0]] ^= 1, rev[ch[ne][1]] ^= 1, rev[ne] = 0; }
    void nodeadd(int ne, int v, int fa){ pre[ne] = fa, val[ne] = v, size[ne] = 1, ch[ne][0] = ch[ne][1] = 0; }
    void build(int& ne, int l, int r, int fa){
        if(l > r) return;
        int m = (l + r)/2; ne = m;
        nodeadd(ne, val[m], fa);
        build(ch[ne][0], l, m - 1, ne), build(ch[ne][1], m + 1, r, ne);
        pushup(ne);
    }
    void rotate(int x, int k){
        int dx = pre[x], ddx = pre[dx];
        pushdown(dx), pushdown(x);
        ch[dx][!k] = ch[x][k], pre[x] = ddx;
        if(ch[x][k]) pre[ch[x][k]] = dx;
        if(ddx) ch[ddx][ch[ddx][1] == dx] = x;
        pre[dx] = x, ch[x][k] = dx;
        pushup(dx); pushup(x);
    }
    void splay(int x, int goal){
        while(pre[x] != goal){
            if(pre[pre[x]] == goal) rotate(x, ch[pre[x]][0] == x);
            else{
                int dx = pre[x], ddx = pre[dx];
                int k = (ch[ddx][0] == dx);
                if(ch[dx][k] == x) rotate(x, !k), rotate(x, k);
                else rotate(dx, k), rotate(x, k);
            }
        }
        pushup(x);
        if(goal == 0) root = x;
    }
    int get_kth(int x, int k){
        pushdown(x);
        if(size[ch[x][0]] == k - 1) return x;
        if(size[ch[x][0]] >= k) return get_kth(ch[x][0], k);
        return get_kth(ch[x][1], k - size[ch[x][0]] - 1);
    }
    void regionrev(int l, int r){
        int x = get_kth(root, l - 1), y = get_kth(root, r + 1);
        splay(x, 0); splay(y, x);
        rev[ch[y][0]] ^= 1;
    }
} S;
int main(){
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    int n = int(s.size());
    S.val[1] = S.val[n+2] = 1000;
    for(int i=0;i<n;i++) S.val[i+2] = s[i];
    S.init(n + 2);
    int k; cin>>k;
    for(int i=0;i<k;i++){
        int l, r; cin>>l>>r;
        S.regionrev(l + 2, r + 2);
    }
    S.dfs(S.root);
    return 0;
}
