#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10000 + 10;
int node[maxn];
bool status;
vector<int> graph[maxn];
void bfs(int n, int type){
    if(node[n] == -1) node[n] = type;
    if(node[n] != type) status = false;
    for(auto g:graph[n]) {
        if(node[g] != -1 && node[g] != 1-type) status = false;
        if(status && node[g] == -1) bfs(g, 1-type);
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t,m,n,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<maxn;i++) node[i] = -1;
        status = true;
        for(int i=0;i<m;i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=n;i++) if(node[i] == -1) bfs(i, 0);
        cout<<(status ? "Correct" : "Wrong")<<endl;
        for(int i=1;i<=n;i++) graph[i].clear();
    }
    return 0;
}
