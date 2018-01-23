#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
int t, n, rec[maxn];
bool graph[maxn][maxn], vis[maxn];
string w, s;
bool search(int p){
    for(int i=1;i<=n;i++)
        if(graph[p][i] && (!vis[i])) {
            vis[i] = true;
            if(!rec[i] || search(rec[i])) { rec[i] = p;return true; }
        }
    return false;
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>t;
    while(t--){
        cin>>n>>s;
        memset(graph, 0, sizeof(graph));memset(rec, 0, sizeof(rec));
        for(int i=0;i<n;i++) {
            cin>>w;
            for(int a=0;a<s.size();a++) for(int b=0;b<w.size();b++) if(s[a] == w[b]) graph[a+1][i+1] = true;
        }
        int res = 0;
        for(int i=0;i<s.size();i++) {
            memset(vis, 0, sizeof(vis));
            if(search(i+1)) res++;
        }
        cout<<(res==s.size() ? "Yes" : "No")<<endl;
    }
    return 0;
}
