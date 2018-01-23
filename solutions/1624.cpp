#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
const int maxn = 10050, maxm = 100050;
vector<int> graph[maxn];
set<int> stop_list;
int dis[maxn], rec[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(rec, 0, sizeof(rec));
    for(int i=0;i<maxn;i++) dis[i] = INT32_MAX;
    int n,m,a,b,res = -1;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>a>>b, graph[a].push_back(b);
        if(b == 1) stop_list.insert(a);
    }
    dis[1] = 0;
    for(int i=0;i<n;i++){
        int curr_node = 0, curr_dis = INT32_MAX;
        for(int j=1;j<=n;j++) if(rec[j] == 0 && (curr_node == 0 || dis[j] < curr_dis)) curr_node = j, curr_dis = dis[j];
        if(stop_list.find(curr_node) != stop_list.end()) { res = curr_dis + 1;break;}
        for(auto e:graph[curr_node]) dis[e] = min(dis[e], curr_dis+1);
        rec[curr_node] = 1;
    }
    cout<<res<<endl;
    return 0;
}
