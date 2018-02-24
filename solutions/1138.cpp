#include <bits/stdc++.h>
using namespace std;
#define d(i, j) min(abs(gnode[i].x - gnode[j].x),abs(gnode[i].y - gnode[j].y))
const int maxn = 1e5+10;
struct node{
    int x,y,id;
    int d = INT32_MAX;
};
node gnode[maxn], snode[maxn];
int vis[maxn];
vector<int> graph[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(vis, 0, sizeof(vis));
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>gnode[i].x>>gnode[i].y, gnode[i].id = i;
        snode[i] = gnode[i];
    }
    sort(snode, snode + n, [](node a, node b){ return a.x < b.x; });
    for(int i = 0; i < n; i++){
        if(i > 0)  graph[snode[i].id].push_back(snode[i-1].id);
        if(i < n-1) graph[snode[i].id].push_back(snode[i+1].id);
    }
    sort(snode, snode + n, [](node a, node b){ return a.y < b.y; });
    for(int i = 0; i < n; i++){
        if(i > 0)  graph[snode[i].id].push_back(snode[i-1].id);
        if(i < n-1) graph[snode[i].id].push_back(snode[i+1].id);
    }
    queue<int> Q;
    Q.push(0), gnode[0].d = 0;
    while(!Q.empty()){
        int curr_node = Q.front();
        vis[curr_node] = 1;
        for(auto dst_node:graph[curr_node]){
            if(gnode[dst_node].d > d(dst_node, curr_node) + gnode[curr_node].d){
                gnode[dst_node].d = d(dst_node, curr_node) + gnode[curr_node].d;
                if(vis[dst_node] == 0) Q.push(dst_node), vis[dst_node] = 1;
            }
        }
        Q.pop();
        vis[curr_node] = 0;
    }
    cout<<gnode[n-1].d<<endl;
    return 0;
}
