#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
int arr[maxn], lc[maxn], rc[maxn];
void dfs(int root){
    cout<<arr[root]<<" ";
    if(lc[root] != -1) dfs(lc[root]);
    if(rc[root] != -1) dfs(rc[root]);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(lc, -1, sizeof(lc)); memset(rc, -1, sizeof(rc));
    int n, root; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        int l = -1, r = -1;
        for(int j=i-1;j>=0;j--) if(arr[j] < arr[i]) { l = j; break; }
        for(int j=i+1;j<n;j++) if(arr[j] < arr[i]) { r = j; break; }
        if(l == -1 && r == -1) root = i;
        else if(l == -1) lc[r] = i;
        else if(r == -1) rc[l] = i;
        else if(arr[l] > arr[r]) rc[l] = i;
        else lc[r] = i;
    }
    dfs(root);
    return 0;
}
