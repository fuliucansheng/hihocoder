#include <iostream>
using namespace std;
const int maxn = 10010;
int group[maxn], store[maxn];
int find_group(int x){
    if(x == group[x]) return x;
    int dx = group[x];
    group[x] = find_group(group[x]);
    store[x] = store[x] ^ store[dx];
    return group[x];
}
bool is_valid(int x, int u, int v){
    int du = find_group(u), dv = find_group(v);
    if(du == dv){
        int s = store[u] != store[v];
        if(s != x) return false;
    }else group[du] = dv, store[du] = x ^ store[u] ^ store[v];
    return true;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        for(int i=0;i<maxn;i++) group[i] = i, store[i] = 0;
        int m, n; cin>>n>>m;
        int rs = 0;
        for(int i=0;i<m;i++){
            int x, u, v; cin>>x>>u>>v;
            if(rs) continue;
            if(!is_valid(x, u, v)) rs = i + 1;
        }
        if(!rs) cout<<"great"<<endl;
        else cout<<"sad"<<endl<<rs<<endl;
    }
    return 0;
}
