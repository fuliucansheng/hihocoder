#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 10010;
vector<int> graph[maxn];
ps arr[maxn];
ps dfs(int u, int fa){
    vector<ps> r;
    for(auto v:graph[u]) if(v != fa) r.push_back(dfs(v, u));
    sort(r.begin(), r.end(), [](ps a, ps b){ return a.second > b.second; });
    int f = arr[u].first, s = arr[u].second;
    for(auto rr:r) if(s < rr.first) f += rr.first - s, s = rr.second; else s -= (rr.first - rr.second);
    return ps(f, s);
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    cout<<dfs(1, 0).first<<endl;
    return 0;
}

