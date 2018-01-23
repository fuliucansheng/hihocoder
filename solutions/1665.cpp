#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int add[maxn<<2],sum[maxn<<2];
void seg_tree_pushdown(int node){
    add[2*node] = add[node];sum[2*node] = add[node];
    add[2*node+1] = add[node];sum[2*node+1] = add[node];
    add[node] = 0;
}
int seg_tree_query(int node, int left, int right, int treeleft, int treeright){
    if(treeleft > right || treeright < left) return 0;
    if(treeleft >= left && treeright <= right) return sum[node];
    int treemid = (treeleft + treeright)/2;
    if(add[node]) seg_tree_pushdown(node);
    int l = seg_tree_query(2*node, left, right, treeleft, treemid);
    int r = seg_tree_query(2*node+1, left, right, treemid+1,treeright);
    return max(l, r);
}
void seg_tree_region_update(int node, int left, int right, int treeleft, int treeright, int value){
    if(treeleft > right || treeright < left) return;
    if(treeleft >= left && treeright <= right) {
        if(value > sum[node]){
            add[node] = value;
            sum[node] = value;
        }
        return;
    }
    int treemid = (treeleft + treeright)/2;
    if(add[node]) seg_tree_pushdown(node);
    seg_tree_region_update(2*node, left, right, treeleft, treemid, value);
    seg_tree_region_update(2*node+1, left, right, treemid+1, treeright, value);
    sum[node] = max(sum[2*node],sum[2*node+1]);
}

int main(){
    //freopen("../input.txt","r",stdin);
    memset(sum, 0, sizeof(sum)); memset(add, 0, sizeof(add));
    int n, l , r; cin>>n;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        int rs = seg_tree_query(1,l,r,0,maxn);
        cout<<rs+1<<endl;
        seg_tree_region_update(1,l,r,0,maxn,rs+1);
    }
    return 0;
}

