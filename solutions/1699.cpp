#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
struct n1{
    int x1,y1,x2,y2;
}arr[maxn];
struct n2{
    int x, y1, y2, nid, v;
    n2(int x_, int y1_, int y2_, int nid_, int v_):x(x_),y1(y1_),y2(y2_),nid(nid_),v(v_){}
    bool operator < (n2 b){
        if(x != b.x) return x < b.x;
        if(v != b.v) return v < b.v;
        if(y1 != b.y1) return y1 < b.y1;
        if(y2 != b.y2) return y2 > b.y2;
        if(v == 1) return arr[nid].x2 > arr[b.nid].x2;
        return 0;
    }
};
int tree[maxn<<2], ans[maxn], n;
void seg_tree_pushdown(int node){ tree[2*node] += tree[node]; tree[2*node+1] += tree[node]; tree[node] = 0; }
int seg_tree_query(int node, int x, int treeleft, int treeright){
    if(treeleft == treeright) return tree[node];
    int treemid = (treeleft + treeright)/2;
    if(tree[node]) seg_tree_pushdown(node);
    if(x <= treemid) return seg_tree_query(2*node, x, treeleft, treemid);
    return seg_tree_query(2*node+1, x, treemid+1,treeright);
}
void seg_tree_region_update(int node, int left, int right, int treeleft, int treeright, int value){
    if(treeleft > right || treeright < left) return;
    if(treeleft >= left && treeright <= right) { tree[node] += value; return; }
    int treemid = (treeleft + treeright)/2;
    if(tree[node]) seg_tree_pushdown(node);
    seg_tree_region_update(2*node, left, right, treeleft, treemid, value);
    seg_tree_region_update(2*node+1, left, right, treemid+1, treeright, value);
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(tree, 0, sizeof(tree)); memset(ans, 0, sizeof(ans));
    cin>>n;
    vector<int> pp;
    for(int i=0;i<n;i++){
        cin>>arr[i].x1>>arr[i].y1>>arr[i].x2>>arr[i].y2;
        pp.push_back(arr[i].y1 * 2); pp.push_back(arr[i].y2 * 2); pp.push_back(arr[i].y1 + arr[i].y2);
    }
    sort(pp.begin(), pp.end()); pp.erase(unique(pp.begin(), pp.end()), pp.end());
    vector<n2> rr;
    for(int i=0;i<n;i++){
        int x1 = arr[i].x1, x2 = arr[i].x2, y1 = arr[i].y1 * 2, y2 = arr[i].y2 * 2;
        y1 = int(lower_bound(pp.begin(), pp.end(), y1) - pp.begin()), y2 = int(lower_bound(pp.begin(), pp.end(), y2) - pp.begin());
        rr.push_back(n2(x1, y1, y2, i, 1)); rr.push_back(n2(x2, y1, y2, i, -1));
    }
    sort(rr.begin(), rr.end());
    for(int i=0;i<int(rr.size());i++){
        if(rr[i].v == 1) ans[rr[i].nid] = seg_tree_query(1, (rr[i].y1 + rr[i].y2) / 2, 0, maxn-1);
        seg_tree_region_update(1, rr[i].y1, rr[i].y2, 0, maxn-1, rr[i].v);
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;
    return 0;
}
