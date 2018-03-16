#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 100010;
vector<int> graph[maxn];
pii dfs(int u, int f){
    pii ret = pii(0, 0);
    int a = -1, b = -1;
    for(auto v:graph[u]) if(v != f){
            pii r = dfs(v, u);
            ret.first = max(ret.first, r.first), ret.second = max(ret.second, r.second);
            if(r.second > a) b = a, a = r.second;
            else if(r.second > b) b = r.second;
        }
    if(a != -1 && b != -1) ret.first = max(ret.first, a + b);
    ret.second++;
    return ret;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    for(int i=1;i<n;i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v), graph[v].push_back(u);
    }
    pii ans = dfs(1, 0);
    cout<<max(ans.first, ans.second - 1)<<endl;
    return 0;
}