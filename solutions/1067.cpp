#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1e5+10;
map<string,int> dict;
string name[MAXN];
vector<int> query[MAXN];
string queryleft[MAXN], queryright[MAXN];
vector<int> tree[MAXN];
int result[MAXN];
int group[MAXN];
int count = 1;
int find_group(int x){ return x == group[x] ? x : group[x] = find_group(group[x]); }
void dfs(int node, int fnode){
    group[node] = node;
    for(int i=0;i<tree[node].size();i++) dfs(tree[node][i], node);
    for(int i=0;i<query[node].size();i++){
        int qid = query[node][i];
        int tp = (node == dict[queryleft[qid]] ? dict[queryright[qid]] : dict[queryleft[qid]]);
        if(!find_group(tp)) continue;
        result[qid] = find_group(tp);
    }
    group[node] = find_group(fnode);
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n,Q;
    string father,son;
    memset(group, 0, sizeof(group));
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>father>>son;
        if(!dict[father]) name[count] = father, dict[father] = count++;
        if(!dict[son]) name[count] = son, dict[son] = count++;
        int df = dict[father], ds = dict[son];
        tree[df].push_back(ds);
    }
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>queryleft[i]>>queryright[i];
        int d1 = dict[queryleft[i]], d2 = dict[queryright[i]];
        query[d1].push_back(i),query[d2].push_back(i);
    }
    dfs(1,1);
    for(int i=0;i<Q;i++) cout<<name[result[i]]<<endl;
    return 0;
}
