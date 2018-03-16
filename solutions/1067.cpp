#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
map<string,int> dict;
string name[maxn];
vector<int> query[maxn], graph[maxn];
string qleft[maxn], qright[maxn];
int result[maxn], group[maxn], cnt = 1;
int find_group(int x){ return x == group[x] ? x : group[x] = find_group(group[x]); }
void dfs(int u, int f){
    group[u] = u;
    for(auto v:graph[u]) dfs(v, u);
    for(int i=0;i<query[u].size();i++){
        int qid = query[u][i];
        int tp = (u == dict[qleft[qid]] ? dict[qright[qid]] : dict[qleft[qid]]);
        if(!find_group(tp)) continue;
        result[qid] = find_group(tp);
    }
    group[u] = find_group(f);
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n, Q;
    string father, son;
    memset(group, 0, sizeof(group));
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>father>>son;
        if(!dict[father]) name[cnt] = father, dict[father] = cnt++;
        if(!dict[son]) name[cnt] = son, dict[son] = cnt++;
        int df = dict[father], ds = dict[son];
        graph[df].push_back(ds);
    }
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>qleft[i]>>qright[i];
        int d1 = dict[qleft[i]], d2 = dict[qright[i]];
        query[d1].push_back(i),query[d2].push_back(i);
    }
    dfs(1,1);
    for(int i=0;i<Q;i++) cout<<name[result[i]]<<endl;
    return 0;
}