#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int MAXN = 2e5+10;
int post[MAXN<<2],arr[MAXN];

void seg_tree_build(int node, int left, int right){
    post[node] = 0;
    if(left == right - 1) return;
    else{
        int mid = (left + right)/2;
        seg_tree_build(2*node, left, mid);
        seg_tree_build(2*node+1, mid, right);
    }
}

void seg_tree_pushdown(int node){
    post[2*node] = post[2*node+1] = post[node];
    post[node] = 0;
}

void seg_tree_query(int node, int treeleft, int treeright){
    int treemid = (treeleft + treeright)/2;
    if(post[node]) { arr[post[node]] = 1;return; }
    if(treeright - treeleft == 1) return;
    seg_tree_query(2*node,treeleft,treemid);
    seg_tree_query(2*node+1,treemid,treeright);
}

void seg_tree_region_update(int node, int left, int right, int treeleft, int treeright, int value){
    if(treeleft >= right || treeright <= left) return;
    if(treeleft >= left && treeright <= right) {
        post[node] = value;
        return;
    }
    int treemid = (treeleft + treeright)/2;
    if(post[node]) seg_tree_pushdown(node);
    seg_tree_region_update(2*node, left, right, treeleft, treemid, value);
    seg_tree_region_update(2*node+1, left, right, treemid, treeright, value);
}

int main(){
    //freopen("../input.txt","r",stdin);
    memset(post, 0, sizeof(post));memset(arr, 0, sizeof(arr));
    int l, r, count = 0, result = 0, N, L;
    set<int> rec;
    map<int,int> dict;
    vector<pair<int,int>> op;
    cin>>N>>L;
    for(int i=0;i<N;i++) {
        cin>>l>>r;
        rec.insert(l),rec.insert(r);
        op.push_back(make_pair(l,r));
    }
    for(auto r:rec) dict[r] = count++;
    seg_tree_build(1, 0, count-1);
    for(int i=0;i<op.size();i++) seg_tree_region_update(1, dict[op[i].first], dict[op[i].second], 0, count-1, i+1);
    seg_tree_query(1, 0, count-1);
    for(int i=1;i<=N;i++) if(arr[i]) result++;
    cout<<result<<endl;
    return 0;
}
