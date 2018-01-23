#include <iostream>
using namespace std;
const int maxn = 100010;
struct SplayTree{
    int size[maxn], pre[maxn], cnt[maxn], add[maxn], ret[maxn], aa[maxn], dd[maxn], val[maxn], ch[maxn][2], tot, root;
    void nodeadd(int ne, int v, int fa){ pre[ne] = fa, val[ne] = v, size[ne] = 1, ch[ne][0] = ch[ne][1] = 0; }
    void pushup(int ne){
        size[ne] = size[ch[ne][0]] + size[ch[ne][1]] + 1;
    }
    void pushdown(int ne){
        if(ne && val[ne] != 1000){
            if(ret[ne]) {
                ret[ch[ne][0]] = ret[ch[ne][1]] = ret[ne]; val[ne] = ret[ne] - 1;
                ret[ne] = add[ne] = aa[ne] = dd[ne] = 0;
            }
            if(add[ne]){
                if(ret[ch[ne][0]]) pushdown(ch[ne][0]);
                if(ret[ch[ne][1]]) pushdown(ch[ne][1]);
                add[ch[ne][0]] += add[ne], add[ch[ne][1]] += add[ne], val[ne] += add[ne], add[ne] = 0;
            }
            if(aa[ne] || dd[ne]) {
                if(ret[ch[ne][0]]) pushdown(ch[ne][0]);
                if(ret[ch[ne][1]]) pushdown(ch[ne][1]);
                aa[ch[ne][0]] += aa[ne];
                aa[ch[ne][1]] += aa[ne] + (size[ch[ne][0]] + 1) * dd[ne];
                val[ne] += aa[ne] + size[ch[ne][0]] * dd[ne];
                dd[ch[ne][0]] += dd[ne], dd[ch[ne][1]] += dd[ne];
                aa[ne] = dd[ne] = 0;
            }
            val[ne] %= 26;
        }
    }
    void init(int n){
        root = 0; pre[0] = size[0] = ch[0][0] = ch[0][1] = add[0] = ret[0] = aa[0] = dd[0] = 0;
        build(root, 1, n, 0);
        pushup(root);
    }
    void build(int& ne, int l, int r, int fa){
        if(l > r) return;
        int m = (l + r)/2; ne = m;
        nodeadd(ne, val[m], fa), cnt[m] = 1;
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
        pushup(dx);
    }
    void splay(int x, int goal){
        pushdown(x);
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
    void regionadd(int l, int r, int v){
        int x = get_kth(root, l - 1), y = get_kth(root, r + 1);
        splay(x, 0), splay(y, x);
        pushdown(ch[y][0]);
        add[ch[y][0]] += v;
    }
    void regionaad(int l, int r, int a, int d){
        int x = get_kth(root, l - 1), y = get_kth(root, r + 1);
        splay(x, 0), splay(y, x);
        pushdown(ch[y][0]);
        aa[ch[y][0]] += a, dd[ch[y][0]] += d;
    }
    void regionret(int l, int r, int v){
        int x = get_kth(root, l - 1), y = get_kth(root, r + 1);
        splay(x, 0), splay(y, x);
        pushdown(ch[y][0]);
        ret[ch[y][0]] = v;
    }
    void regionexc(int k, int n){
        int x = get_kth(root, 1), y = get_kth(root, k + 1);
        splay(x, 0); splay(y, x);
        int tmp_left = ch[y][0]; ch[y][0] = 0;
        x = get_kth(root, n + 2 - k); y = get_kth(root, n + 3 - k);
        splay(x, 0); splay(y, x);
        ch[y][0] = tmp_left, pre[tmp_left] = y;
    }
    void dfs(int ne){
        if(!ne) return;
        pushdown(ne);
        dfs(ch[ne][0]);
        if(val[ne] != 1000) cout<<char(val[ne] + 'A');
        dfs(ch[ne][1]);
    }
} S;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, m; cin>>n>>m;
    string s; cin>>s;
    S.val[1] = S.val[n+2] = 1000;
    for(int i=0;i<n;i++) S.val[i+2] = s[i] - 'A';
    S.init(n+2);
    for(int _=0;_<m;_++){
        string op; cin>>op;
        int t, i, j, k; char x;
        cin>>t;
        if(t == 1) cin>>i>>j>>x, S.regionret(i+1, j+1, x - 64);
        if(t == 2) cin>>i>>j>>k, S.regionadd(i+1, j+1, k);
        if(t == 3) cin>>k, S.regionexc(k+1, n);
        if(t == 4) cin>>i>>j, S.regionaad(i+1, j+1, 1, 1);
    }
    S.dfs(S.root);
    return 0;
}
