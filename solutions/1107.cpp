#include <bits/stdc++.h>
using namespace std;
const int maxchild = 26, maxnode = 2000010;
struct Trie {
    int graph[maxnode][maxchild], cnt[maxnode];
    int sz, ct;
    Trie(){
        sz = 1, ct = 0;
        memset(graph, 0, sizeof(graph));memset(cnt, 0, sizeof(cnt));
    }
    int idx(char s) { return s - 'a'; }
    void insert(string str) {
        int u = 0;
        for(int i = 0; i < str.size(); i++) {
            int c = idx(str[i]);
            if(!graph[u][c]) graph[u][c] = sz++;
            u = graph[u][c];
            cnt[u]++;
        }
    }
    void dfs(int s){
        if(s && cnt[s] <= 5){ ct++; return; }
        for(int i=0;i<maxchild;i++) if(graph[s][i]) dfs(graph[s][i]);
    }
} T;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    string s;
    for(int i=0;i<n;i++) cin>>s, T.insert(s);
    T.dfs(0);
    cout<<T.ct<<endl;
    return 0;
}
