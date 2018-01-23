#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 100010;
vector<int> graph[maxn];
int n;
ps dfs(int u, int fa){
    ps rs = ps(1, 0);
    for(auto v:graph[u])
        if(v != fa){
            ps r = dfs(v, u);
            rs.first += r.first, rs.second += r.second;
        }
    if(rs.first%2 == 0) rs.second++;
    return rs;
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    cout<<dfs(1, 0).second-1<<endl;
    return 0;
}

