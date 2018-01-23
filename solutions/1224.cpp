#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
const int maxn = 100010;
vector<int> graph[maxn];
int n;
p dfs(int u){
    int rs = 0, ht = 0;
    vector<int> rec;
    for(auto v:graph[u]){
        p r = dfs(v);
        ht = max(ht, r.second), rec.push_back(r.second), rs = max(rs, r.first);
    }
    if(rec.size() > 1) {
        sort(rec.begin(), rec.end(), greater<int>());
        rs = max(rec[0] + rec[1] + 1, max(rs, ht)) + 1, ht += 1;
    }else if(rec.size() == 1) rs = max(rs, ht) + 1, ht++;
    return p(rs, ht);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    cout<<dfs(1).first<<endl;
    return 0;
}

