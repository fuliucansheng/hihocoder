#include <iostream>
using namespace std;
const int maxn = 25;
typedef pair<int,int> p;
int height[maxn];
bool is_valid(p n, p l, p r){
    return n.first >= l.first && n.second >= l.second && n.first <= r.first && n.second <= r.second;
}
int dfs(p c, p l, p r, int h){
    if(h == 1) return is_valid(c,l,r);
    p lc = p(c.first+height[h], c.second-height[h]), rc = p(c.first+height[h], c.second+height[h]);
    if(is_valid(c,l,r)) return dfs(lc,l,r,h-1)+dfs(rc,l,r,h-1)+1;
    else return dfs(lc,l,r,h-1)+dfs(rc,l,r,h-1);
}
int main(){
    //freopen("../input.txt","r",stdin);
    for(int i=0;i<4;i++) height[i] = i;
    for(int i=4;i<maxn;i++) height[i] = 2*height[i-1];
    int m,n;
    cin>>n>>m;
    p l,r;
    for(int i=0;i<m;i++){
        cin>>l.first>>l.second>>r.first>>r.second;
        cout<<dfs(p(0,0),l,r,n)<<endl;
    }
    return 0;
}
