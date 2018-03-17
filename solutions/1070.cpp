#include <bits/stdc++.h>
using namespace std;

void seg_tree_build(int node, int left, int right, int T[], int A[]){
    if(left == right) T[node] = A[left];
    else{
        int mid = (left + right)/2;
        seg_tree_build(2*node, left, mid, T, A);
        seg_tree_build(2*node+1, mid+1, right, T, A);
        T[node] = min(T[2*node], T[2*node+1]);
    }
}

int seg_tree_query(int node, int left, int right, int treeleft, int treeright, int T[]){
    if(treeleft > right || treeright < left) return INT32_MAX;
    if(treeleft >= left && treeright <= right) return T[node];
    int treemid = (treeleft + treeright)/2;
    int l = seg_tree_query(2*node, left, right, treeleft, treemid, T);
    int r = seg_tree_query(2*node+1, left, right, treemid+1, treeright, T);
    return min(l,r);
}

void seg_tree_update(int node, int left, int right, int ind, int add, int T[]){
    if(left == right)  { T[node] = add; return; }
    int mid = (left + right)/2;
    if(ind <= mid) seg_tree_update(2*node, left, mid, ind, add, T);
    else seg_tree_update(2*node+1, mid+1, right, ind, add, T);
    T[node] = min(T[2*node], T[2*node+1]);
}

int main(){
    //freopen("../input.txt","r",stdin);
    int n, Q, op, p1, p2;
    scanf("%d", &n);
    int arr[n],segtree[n<<2];
    memset(segtree, 0, sizeof(segtree));
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    seg_tree_build(1, 0, n-1, segtree, arr);
    scanf("%d", &Q);
    while(Q--){
        scanf("%d%d%d", &op, &p1, &p2);
        if(op == 1) seg_tree_update(1, 0, n-1, p1-1, p2, segtree);
        else printf("%d\n", seg_tree_query(1, p1-1, p2-1, 0, n-1, segtree));
    }
    return 0;
}
