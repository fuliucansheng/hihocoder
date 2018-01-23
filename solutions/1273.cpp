#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define is_in(a, b) (a.x > b.l.x && a.x < b.r.x && a.y > b.l.y && a.y < b.r.y)
const int maxn = 1010;
struct ps{
    int x, y;
    ps(){}
    ps(int xx, int yy):x(xx),y(yy){}
};
struct im{
    ps l, r;
} arr[maxn];
int cnt[maxn], w, h, n;
bool conner[maxn];
vector<int> graph[maxn];
int cr_in(int i, int j){
    ps ilt = ps(arr[i].l.x, arr[i].r.y), irt = arr[i].r, ilb = arr[i].l, irb = ps(arr[i].r.x, arr[i].l.y);
    int rs = 0;
    if(is_in(ilb, arr[j])) rs |= (1<<0);
    if(is_in(ilt, arr[j])) rs |= (1<<1);
    if(is_in(irt, arr[j])) rs |= (1<<2);
    if(is_in(irb, arr[j])) rs |= (1<<3);
    return rs;
}
bool area(int i, int j){
    int imx = max(arr[i].l.x, arr[i].r.x), inx = min(arr[i].l.x, arr[i].r.x);
    int imy = max(arr[i].l.y, arr[i].r.y), iny = min(arr[i].l.y, arr[i].r.y);
    int jmx = max(arr[j].l.x, arr[j].r.x), jnx = min(arr[j].l.x, arr[j].r.x);
    int jmy = max(arr[j].l.y, arr[j].r.y), jny = min(arr[j].l.y, arr[j].r.y);
    return not ((jnx >= imx || jmx <= inx) || (jny >= imy || jmy <= iny));
}
void dfs(int u){
    cnt[u] = 1;
    for(auto v:graph[u]) if(!cnt[v]) dfs(v);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>w>>h>>n;
    for(int i=0;i<n;i++) cin>>arr[i].l.x>>arr[i].l.y>>arr[i].r.x>>arr[i].r.y;
    for(int i=n-1;i>=0;i--){
        int cr = 0;
        for(int j=i+1;j<n;j++) {
            cr |= cr_in(i,j);
            if(area(i,j)) graph[i].push_back(j);
        }
        conner[i] = (cr != 15);
    }
    int rs = 1, rp = n-1;
    for(int i=n-1;i>=0;i--){
        if(!conner[i]) continue;
        memset(cnt, 0, sizeof(cnt));
        dfs(i);
        int c = 0;
        for(int j=i;j<n;j++) c += cnt[j];
        if(c >= rs) rs = c, rp = i;
    }
    cout<<rs<<" "<<rp+1<<endl;
    return 0;
}
