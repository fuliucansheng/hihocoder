#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 1e5+10;
map<string,int> dict;
vector<int> tree[MAXN];
int itree[MAXN],height[MAXN];
string name[MAXN];
int count = 1;
void node_height(int node, int hgt){
    height[node] = hgt;
    for(int i=0;i<tree[node].size();i++) node_height(tree[node][i],hgt+1);
}
string query(string name1, string name2){
    int d1 = dict[name1], d2 = dict[name2], h1 = height[d1], h2 = height[d2];
    if(h1 < h2) for(int i=h2;i>h1;i--) d2 = itree[d2];
    else if(h1 > h2) for(int i=h1;i>h2;i--) d1 = itree[d1];
    int h = h1;
    while(h > 1 && d1 != d2) d1 = itree[d1], d2 = itree[d2], h--;
    return name[d1];
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n,Q;
    string father,son,name1,name2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>father>>son;
        if(!dict[father]) name[count] = father, dict[father] = count++;
        if(!dict[son]) name[count] = son, dict[son] = count++;
        int df = dict[father], ds = dict[son];
        tree[df].push_back(ds), itree[ds] = df;
    }
    node_height(1,1);
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>name1>>name2;
        cout<<query(name1,name2)<<endl;
    }
    return 0;
}
