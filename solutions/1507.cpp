#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 100010;
int fa[maxn], rec[maxn], n;
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(fa, 0, sizeof(fa)); memset(rec, -1, sizeof(rec));
    cin>>n;
    vector<int> rs;
    for(int i=1;i<=n;i++){
        int u, v; cin>>u>>v;
        if(rec[v] == -1 && v != 1 && u != v) fa[v] = u, rec[v] = i;
        else if(v == 1 || u == v) rs.push_back(i);
        else rs.push_back(rec[v]), rs.push_back(i);
    }
    for(auto r:rs) cout<<r<<" "; cout<<endl;
    return 0;
}
