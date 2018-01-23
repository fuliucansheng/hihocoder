#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;
int add[MAXN<<2],sum[MAXN<<2],arr[MAXN],ret[MAXN<<2];

void seg_tree_build(int node, int left, int right){
    if(left == right) sum[node] = arr[left];
    else{
        int mid = (left + right)/2;
        seg_tree_build(2*node, left, mid);
        seg_tree_build(2*node+1, mid+1, right);
        sum[node] = sum[2*node] + sum[2*node+1];
    }
}

void seg_tree_pushdown(int node, int region_length, int type){
    if(type == 0){
        add[2*node] += add[node];sum[2*node] += add[node]*(region_length - region_length/2);
        add[2*node+1] += add[node];sum[2*node+1] += add[node]*(region_length/2);
        add[node] = 0;
    }else{
        ret[2*node] = ret[2*node+1] = ret[node];
        sum[2*node] = ret[node]*(region_length - region_length/2);
        sum[2*node+1] = ret[node]*(region_length/2);
        ret[node] = 0;
        add[2*node] = add[2*node+1] = 0;
    }
}

int seg_tree_query(int node, int left, int right, int treeleft, int treeright){
    if(treeleft > right || treeright < left) return 0;
    if(treeleft >= left && treeright <= right) return sum[node];
    int treemid = (treeleft + treeright)/2;
    if(ret[node]) seg_tree_pushdown(node, treeright-treeleft+1, 1);
    if(add[node]) seg_tree_pushdown(node, treeright-treeleft+1, 0);
    int l = seg_tree_query(2*node, left, right, treeleft, treemid);
    int r = seg_tree_query(2*node+1, left, right, treemid+1,treeright);
    return l+r;
}

void seg_tree_region_update(int node, int left, int right, int treeleft, int treeright, int value, int type){
    if(treeleft > right || treeright < left) return;
    if(treeleft >= left && treeright <= right) {
        if(type == 0){
            add[node] += value;
            sum[node] += value*(treeright-treeleft+1);
        }else{
            add[node] = 0;
            ret[node] = value;
            sum[node] = value*(treeright-treeleft+1);
        }
        return;
    }
    int treemid = (treeleft + treeright)/2;
    if(ret[node]) seg_tree_pushdown(node, treeright-treeleft+1, 1);
    if(add[node]) seg_tree_pushdown(node, treeright-treeleft+1, 0);
    seg_tree_region_update(2*node, left, right, treeleft, treemid, value, type);
    seg_tree_region_update(2*node+1, left, right, treemid+1, treeright, value, type);
    sum[node] = sum[2*node] + sum[2*node+1];
}

int main(){
    //freopen("../input.txt","r",stdin);
    memset(sum, 0, sizeof(sum));memset(add, 0, sizeof(add));
    int m,n,t,l,r,v;
    cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>arr[i];
    seg_tree_build(1,0,n);
    while(m--){
        cin>>t>>l>>r>>v;
        seg_tree_region_update(1,l,r,0,n,v,t);
        cout<<seg_tree_query(1,0,n,0,n)<<endl;
    }
    return 0;
}
