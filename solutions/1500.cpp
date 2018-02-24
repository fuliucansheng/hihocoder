#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2010;
vector<int> graph[maxn];
struct node{
    int fa, in, ip, cc;
} arr[maxn];
int dfs(int u){
    if(graph[u].size() == 0) return arr[u].cc;
    int ans = INT32_MAX;
    vector<pii> rc = { pii(0,0) };
    for(auto v:graph[u]){
        int vv = dfs(v);
        if(vv != -1){
            int rcz = int(rc.size());
            for(int i=0;i<rcz;i++) rc.push_back(pii(rc[i].first + arr[v].ip, rc[i].second + vv));
        }
    }
    for(auto rr:rc) if(rr.first >= arr[u].in) ans = min(ans, rr.second);
    return ans == INT32_MAX ? -1 : ans + arr[u].cc;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].fa>>arr[i].in>>arr[i].ip>>arr[i].cc;
        graph[arr[i].fa].push_back(i);
    }
    int ans = dfs(graph[0][0]);
    cout<<ans<<endl;
    return 0;
}
