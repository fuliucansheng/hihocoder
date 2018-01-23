#include <iostream>
#include <vector>
using namespace std;
const int maxn = 26;
vector<int> graph[maxn];
vector<bool> vis[maxn];
int ms, ss, fs, ts;
void dfs(int u, int t){
    if(u == t) return;
    int ns = 0;
    if(u == 'm' - 'a') ns = ((ms < vis[u].size() &&  !vis[u][ms]) ? ms : 1 - ms);
    if(u == 's' - 'a') ns = ((ss < vis[u].size() &&  !vis[u][ss]) ? ss : 1 - ss);
    if(u == 'f' - 'a') ns = ((fs < vis[u].size() &&  !vis[u][fs]) ? fs : 1 - fs);
    if(u == 't' - 'a') ns = ((ts < vis[u].size() &&  !vis[u][ts]) ? ts : 1 - ts);
    if(!vis[u][ns]) vis[u][ns] = true, dfs(graph[u][ns], t);
}
int g(int s){
    ms = ((s&1) != 0), ss = ((s&2) != 0), fs = ((s&4) != 0), ts = ((s&8) != 0);
    for(int i=0;i<maxn;i++) for(int j=0;j<vis[i].size();j++) vis[i][j] = false;
    int rs = 0;
    for(int i=0;i<maxn;i++){
        int ns = 0;
        if(i == 'm' - 'a') ns = ((ms < vis[i].size() &&  !vis[i][ms]) ? ms : 1 - ms);
        if(i == 's' - 'a') ns = ((ss < vis[i].size() &&  !vis[i][ss]) ? ss : 1 - ss);
        if(i == 'f' - 'a') ns = ((fs < vis[i].size() &&  !vis[i][fs]) ? fs : 1 - fs);
        if(i == 't' - 'a') ns = ((ts < vis[i].size() &&  !vis[i][ts]) ? ts : 1 - ts);
        if(ns < vis[i].size() && !vis[i][ns]) vis[i][ns] = true, dfs(graph[i][ns], i), rs++;
    }
    return rs;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    while(n--){
        string s, t; cin>>s>>t;
        for(int i=0;i<maxn;i++) graph[i].clear(), vis[i].clear();
        int rs = 0, ds = 0;
        for(int i=0;i<s.size();i++) if(s[i] != t[i]) graph[s[i]-'a'].push_back(t[i]-'a'), vis[s[i]-'a'].push_back(false), ds++;
        for(int i=0;i<16;i++) rs = max(rs, g(i));
        cout<<ds-rs<<endl;
    }
    return 0;
}
