#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5+10;
int group[maxn];
int find_group(int x){
    return x == group[x] ? x : find_group(group[x]);
}
void union_group(int x, int y){
    int dx = find_group(x), dy = find_group(y);
    group[dx] = group[dy] = min(dx, dy);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        int m, n, u, v; cin>>n>>m;
        for(int i=0;i<=n;i++) group[i] = i;
        bool status = true;
        if(m != n-1) status = false;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            int du = find_group(u), dv = find_group(v);
            if(du == dv) status = false;
            union_group(du, dv);
        }
        cout<<(status ? "YES" : "NO")<<endl;
    }
    return 0;
}
