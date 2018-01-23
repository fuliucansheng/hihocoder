#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <map>
using namespace std;
const int maxn = 20010, maxm = 100010;
vector<pair<int,int>> graph[maxn];
int bccno[maxm], pre[maxn], low[maxn], dfs_clock = 0, bcc_cnt = 0, n, m;
stack<int> S;
map<int,int> dict;
int dfs(int u, int fa){
    int lowu = pre[u] = ++dfs_clock;
    for(auto v:graph[u]){
        int e = v.first;
        if(!pre[v.second]){
            S.push(e);
            int lowv = dfs(v.second, u);
            lowu = min(lowu, lowv);
            if(lowv >= pre[u]){
                bcc_cnt++;
                for(;;){
                    int x = S.top(); S.pop();
                    bccno[x] = bcc_cnt;
                    if(x == e) break;
                }
            }
        }else if(pre[v.second] < pre[u] && v.second != fa) S.push(e), lowu = min(lowu, pre[v.second]);
    }
    low[u] = lowu;
    return lowu;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(pre, 0, sizeof(pre));memset(bccno, 0, sizeof(bccno));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(make_pair(i,v)), graph[v].push_back(make_pair(i,u));
    }
    dfs(1, -1);
    for(int i=1;i<=m;i++) if(!dict[bccno[i]]) dict[bccno[i]] = i;
    cout<<bcc_cnt<<endl;
    for(int i=1;i<=m;i++) cout<<dict[bccno[i]]<<" ";cout<<endl;
    return 0;
}

