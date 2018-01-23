#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 200010;
struct SplayTree{
    int size[maxn], pre[maxn], id[maxn], ch[maxn][2], tot, root;
    ll sum[maxn], add[maxn], val[maxn];
    void nodeadd(int ne, int d, ll v, int fa){ pre[ne] = fa, id[ne] = d, sum[ne] = val[ne] = v, size[ne] = 1, ch[ne][0] = ch[ne][1] = 0; }
    void nodedel(int ne){ pre[ne] = size[ne] = 0; sum[ne] = val[ne] = 0; ch[ne][0] = ch[ne][1] = 0; }
    void pushup(int ne){
        size[ne] = size[ch[ne][0]] + size[ch[ne][1]] + 1;
        sum[ne] = sum[ch[ne][0]] + sum[ch[ne][1]] + val[ne];
    }
    void pushdown(int ne){
        if(add[ne] != 0) {
            add[ch[ne][0]] += add[ne], add[ch[ne][1]] += add[ne], val[ne] += add[ne];
            sum[ch[ne][0]] += add[ne] * size[ch[ne][0]], sum[ch[ne][1]] += add[ne] * size[ch[ne][1]], sum[ne] += add[ne] * size[ne];
            add[ne] = 0;
        }
    }
    void init(){
        root = pre[0] = size[0] = ch[0][0] = ch[0][1] = 0, tot = 2;
        sum[0] = add[0] = 0;
        id[1] = 0, id[2] = 100000001; memset(val, 0, sizeof(val));
        build(root, 1, 2, 0);
        pushup(root);
    }
    void build(int& ne, int l, int r, int fa){
        if(l > r) return;
        int m = (l + r)/2; ne = m;
        nodeadd(ne, id[m], val[m], fa);
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
        pushup(dx), pushup(x);
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
    int prec(int ne, int x){
        if(ch[ne][0] && id[ne] > x) return prec(ch[ne][0], x);
        if(ch[ne][1] && id[ne] <= x) {
            int rne = prec(ch[ne][1], x);
            return id[rne] <= x ? rne : ne;
        }
        return ne;
    }
    int sufc(int ne, int x){
        if(ch[ne][1] && id[ne] < x) return sufc(ch[ne][1], x);
        if(ch[ne][0] && id[ne] >= x){
            int lne = sufc(ch[ne][0], x);
            return id[lne] >= x ? lne : ne;
        }
        return ne;
    }
    void _insert(int d, ll v){
        int p = prec(root, d), s = sufc(root, d);
        splay(p, 0); splay(s, p);
        nodeadd(++tot, d, v, ch[root][1]);
        ch[ch[root][1]][0] = tot;
        for(int z=ch[root][1];z;z=pre[z]) pushup(z);
    }
    void _delete(int l, int r){
        int p = prec(root, l - 1), s = sufc(root, r + 1);
        splay(p, 0); splay(s, p);
        int reg = ch[ch[root][1]][0]; nodedel(reg);
        ch[ch[root][1]][0] = 0;
        for(int z=s;z;z=pre[z]) pushup(z);
    }
    void regionadd(int l, int r, ll v){
        int x = prec(root, l - 1), y = sufc(root, r + 1);
        splay(x, 0), splay(y, x);
        add[ch[y][0]] += v, sum[ch[y][0]] += v * size[ch[y][0]];
    }
    ll regionsum(int l, int r){
        int x = prec(root, l - 1), y = sufc(root, r + 1);
        splay(x, 0), splay(y, x);
        return sum[ch[y][0]];
    }
} S;
int main(){
    //freopen("../input.txt", "r", stdin);
    S.init();
    int n; cin>>n;
    for(int i=0;i<n;i++){
        char c; cin>>c;
        if(c == 'I'){
            int d, v; cin>>d>>v;
            S._insert(d, v);
        }else if(c == 'Q'){
            int a, b; cin>>a>>b;
            cout<<S.regionsum(a, b)<<endl;
        }else if(c == 'M'){
            int a, b; ll v; cin>>a>>b>>v;
            S.regionadd(a, b, v);
        }else{
            int a, b; cin>>a>>b;
            S._delete(a, b);
        }
    }
    return 0;
}
