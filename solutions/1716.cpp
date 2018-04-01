#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
vector<int> graph[maxn];
map<string,int> dict;
set<int> rc;
vector<int> ans;
string idct[maxn], s;
int n, c = 1, r = -1;
void dfs(int u){
    if(!rc.count(u)) ans.push_back(u);
    for(auto v:graph[u]) dfs(v);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>s;
    idct[c] = s, dict[s] = c++;
    r = dict[s];
    for(int i = 0; i < n; i++) {
        string op, name, son; cin>>op>>name;
        if(op == "birth") {
            cin>>son;
            if(!dict.count(name)) idct[c] = name, dict[name] = c++;
            if(!dict.count(son)) idct[c] = son, dict[son] = c++;
            int u = dict[name], v = dict[son];
            graph[u].push_back(v);
        }else{
            if(!dict.count(name)) idct[c] = name, dict[name] = c++;
            rc.insert(dict[name]);
        }
    }
    dfs(dict[s]);
    for(int i=0;i<int(ans.size());i++) if(ans[i] != r) cout<<idct[ans[i]]<<endl;
    return 0;
}


