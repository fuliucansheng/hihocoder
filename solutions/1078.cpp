#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;
int ret[MAXN<<2],sum[MAXN<<2],arr[MAXN];

void seg_tree_build(int node, int left, int right){
    if(left == right) sum[node] = arr[left];
    else{
        int mid = (left + right)/2;
        seg_tree_build(2*node, left, mid);
        seg_tree_build(2*node+1, mid+1, right);
        sum[node] = sum[2*node] + sum[2*node+1];
    }
}

void seg_tree_pushdown(int node, int region_length){
    ret[2*node] = ret[node];sum[2*node] = ret[node]*(region_length - region_length/2);
    ret[2*node+1] = ret[node];sum[2*node+1] = ret[node]*(region_length/2);
    ret[node] = 0;
}

int seg_tree_query(int node, int left, int right, int treeleft, int treeright){
    if(treeleft > right || treeright < left) return 0;
    if(treeleft >= left && treeright <= right) return sum[node];
    int treemid = (treeleft + treeright)/2;
    if(ret[node]) seg_tree_pushdown(node, treeright-treeleft+1);
    int l = seg_tree_query(2*node, left, right, treeleft, treemid);
    int r = seg_tree_query(2*node+1, left, right, treemid+1,treeright);
    return l+r;
}

void seg_tree_region_update(int node, int left, int right, int treeleft, int treeright, int value){
    if(treeleft > right || treeright < left) return;
    if(treeleft >= left && treeright <= right) {
        ret[node] = value;
        sum[node] = value*(treeright-treeleft+1);
        return;
    }
    int treemid = (treeleft + treeright)/2;
    if(ret[node]) seg_tree_pushdown(node, treeright-treeleft+1);
    seg_tree_region_update(2*node, left, right, treeleft, treemid, value);
    seg_tree_region_update(2*node+1, left, right, treemid+1, treeright, value);
    sum[node] = sum[2*node] + sum[2*node+1];
}

int main(){
    //freopen("../input.txt","r",stdin);
    memset(ret, 0, sizeof(ret));memset(sum, 0, sizeof(sum));memset(arr, 0, sizeof(arr));
    int n,Q,op,l,r,v;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    seg_tree_build(1,1,n);
    cin>>Q;
    while(Q--){
        cin>>op;
        if(op == 1) cin>>l>>r>>v, seg_tree_region_update(1,l,r,1,n,v);
        else cin>>l>>r, cout<<seg_tree_query(1,l,r,1,n)<<endl;
    }
    return 0;
}
