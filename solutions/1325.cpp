#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100010, mnv = -1000000001, mxv = 1000000001;
struct SplayTree{
    int pre[maxn], val[maxn], ch[maxn][2], tot, root = 0;
    void init(){
        memset(pre, 0, sizeof(pre)), memset(ch, 0, sizeof(ch));
        val[1] = mnv, val[2] = mxv, tot = 2;
        build(root, 1, 2, 0);
    }
    void nodeadd(int ne, int v, int fa){ pre[ne] = fa, val[ne] = v, ch[ne][0] = ch[ne][1] = 0; }
    void build(int& ne, int l, int r, int fa){
        if(l > r) return;
        int m = (l + r)/2; ne = m;
        nodeadd(m, val[m], fa);
        build(ch[m][0], l, m - 1, m), build(ch[m][1], m + 1, r, m);
    }
    void rotate(int x, int k){
        int dx = pre[x], ddx = pre[dx];
        ch[dx][!k] = ch[x][k], pre[x] = ddx;
        if(ch[x][k]) pre[ch[x][k]] = dx;
        if(ddx) ch[ddx][ch[ddx][1] == dx] = x;
        pre[dx] = x, ch[x][k] = dx;
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
        if(goal == 0) root = x;
    }
    int search(int ne, int v){
        if(ch[ne][0] && val[ne] > v) return search(ch[ne][0], v);
        if(ch[ne][1] && val[ne] < v) return search(ch[ne][1], v);
        return ne;
    }
    int prec(int ne, int x){
        if(ch[ne][0] && val[ne] > x) return prec(ch[ne][0], x);
        if(ch[ne][1] && val[ne] <= x) {
            int rne = prec(ch[ne][1], x);
            return val[rne] <= x ? rne : ne;
        }
        return ne;
    }
    int sufc(int ne, int x){
        if(ch[ne][1] && val[ne] < x) return sufc(ch[ne][1], x);
        if(ch[ne][0] && val[ne] >= x){
            int lne = sufc(ch[ne][0], x);
            return val[lne] >= x ? lne : ne;
        }
        return ne;
    }
    void insert(int x){
        int dx = search(root, x);
        if(val[dx] != x){
            int p = prec(root, x), s = sufc(root, x);
            splay(p, 0); splay(s, p);
            nodeadd(++tot, x, ch[root][1]);
            ch[ch[root][1]][0] = tot;
        }
    }
} S;
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    S.init();
    for(int _=0;_<n;_++){
        char c; cin>>c;
        int k; cin>>k;
        if(c == 'I') S.insert(k); else cout<<S.val[S.prec(S.root, k)]<<endl;
    }
    return 0;
}
