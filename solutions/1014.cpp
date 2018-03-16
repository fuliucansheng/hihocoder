#include <bits/stdc++.h>
using namespace std;
const int maxchild = 26, maxnode = 1000010;
struct Trie {
    int graph[maxnode][maxchild], cnt[maxnode], val[maxnode], sz;
    Trie() { sz = 1; memset(graph, 0, sizeof(graph)); memset(val, 0, sizeof(val)); memset(cnt, 0, sizeof(cnt)); }
    int idx(char s) { return s - 'a'; }
    void insert(string str, int v) {
        int u = 0;
        for (int i = 0; i < str.size(); i++) {
            cnt[u]++;
            int c = idx(str[i]);
            if (!graph[u][c]) graph[u][c] = sz++;
            u = graph[u][c];
        }
        val[u] = v, cnt[u]++;
    }
    int search(string str){
        int u = 0;
        for(int i=0;i<int(str.size());i++) {
            int c = idx(str[i]);
            if(!graph[u][c]) return 0;
            u = graph[u][c];
        }
        return cnt[u];
    }
}tre;
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        tre.insert(s, i + 1);
    }
    int m; cin>>m;
    for(int i=0;i<m;i++){
        string s; cin>>s;
        cout<<tre.search(s)<<endl;
    }
    return 0;
}

