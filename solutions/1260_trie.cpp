#include <cstring>
#include <iostream>
using namespace std;
const int maxchild = 26, maxnode = 1e5+10;
string s;
struct Trie{
    int graph[maxnode][maxchild], val[maxnode];
    bool vis[maxnode];
    int sz;
    Trie() { sz = 1; memset(graph, 0, sizeof(graph)); memset(val, 0, sizeof(val)); memset(vis, 0, sizeof(vis)); }
    int idx(char s) { return s - 'a'; }
    void insert(string str, int v) {
        int u = 0;
        for (int i = 0; i < str.size(); i++) {
            int c = idx(str[i]);
            if (!graph[u][c]) graph[u][c] = sz++;
            u = graph[u][c];
        }
        val[u] = v;
    }
    int dfs(int p, int x, bool skip = false){
        if(val[p] && x == s.size() && !vis[val[p]] && skip) return vis[val[p]] = true, 1;
        int rs = 0, c = idx(s[x]);
        if(!skip) for(int i=0;i<maxchild;i++) if(graph[p][i]) rs += dfs(graph[p][i], x, !skip);
        if(graph[p][c] && x < s.size()) rs += dfs(graph[p][c], x+1, skip);
        return rs;
    }
} tre;
int main(){
    //freopen("../input.txt","r",stdin);
    int m, n; cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s, tre.insert(s, i+1);
    for(int i=0;i<m;i++){
        cin>>s;
        cout<<tre.dfs(0, 0)<<endl;
    }
    return 0;
}
