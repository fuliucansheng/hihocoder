#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxchild = 26, maxnode = 1e6+10;
struct Trie{
    int graph[maxnode][maxchild];
    int sz;
    Trie() { sz = 1, memset(graph, 0, sizeof(graph)); }
    int idx(char s) { return s - 'a'; }
    void insert(string str, int v[]) {
        int u = 0;
        for (int i = 0; i < str.size(); i++) {
            int c = idx(str[i]);
            if (!graph[u][c]) graph[u][c] = sz++;
            u = graph[u][c];
            v[i+1] = u;
        }
    }
    int query(string str){
        int u = 0;
        for(int i=0;i<int(str.size());i++){
            int c = idx(str[i]);
            if(!graph[u][c]) return -1;
            u = graph[u][c];
        }
        return u;
    }
} tre;
int a[12], b[12];
int main() {
    //freopen("../input.txt", "r" , stdin);
    int m, n; cin>>n>>m;
    unordered_map<ll,ll> rec;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        int v; cin>>v;
        tre.insert(s, a);
        reverse(s.begin(), s.end());
        tre.insert(s, b);
        for(int aa=0;aa<=int(s.size());aa++) for(int bb=0;bb<=int(s.size());bb++) rec[ll(a[aa])*1000010+ll(b[bb])] = max(rec[ll(a[aa])*1000010+ll(b[bb])], ll(v));
    }
    for(int i=0;i<m;i++){
        string p, s; cin>>p>>s;
        reverse(s.begin(), s.end());
        int rp = tre.query(p), rs = tre.query(s);
        if(rp != -1 && rs != -1){
            if(rec.find(ll(rp)*1000010+ll(rs)) != rec.end()) cout<<rec[ll(rp)*1000010+ll(rs)]<<endl;
            else cout<<-1<<endl;
        }else cout<<-1<<endl;
    }
    return 0;
}
