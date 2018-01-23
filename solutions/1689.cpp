#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1000010;
vector<int> g1[maxn], g2[maxn];
bool v1[maxn], v2[maxn];
int m, n;
bool dfs1(int u, int t){
    if(u == t) return true;
    v1[u] = true;
    for(auto v:g1[u]) if(!v1[v]) if(dfs1(v, t)) return true;
    return false;
}
bool dfs2(int u, int t){
    if(u == t) return true;
    v2[u] = true;
    for(auto v:g2[u]) if(!v2[v]) if(dfs2(v, t)) return true;
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    memset(v1, 0, sizeof(v1)); memset(v2, 0, sizeof(v2));
    for(int i=1;i<=m;i++){
        string a, op, b; cin>>a>>op>>b;
        int aa = atoi(a.substr(1).c_str()), bb = atoi(b.substr(1).c_str());
        g1[aa].push_back(bb), g2[bb].push_back(aa);
        if(op == "=") {
            g1[bb].push_back(aa), g2[aa].push_back(bb);
            if((bb == 1 || v1[bb]) && dfs1(bb, n)) return cout<<i<<endl, 0;
            if((aa == 1 || v2[aa]) && dfs2(aa, n)) return cout<<i<<endl, 0;
        }
        if((aa == 1 || v1[aa]) && dfs1(aa, n)) return cout<<i<<endl, 0;
        if((bb == 1 || v2[bb]) && dfs2(bb, n)) return cout<<i<<endl, 0;
    }
    cout<<-1<<endl;
    return 0;
}
