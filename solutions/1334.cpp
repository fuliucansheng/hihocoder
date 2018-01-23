#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 45;
int graph[maxn][maxn], arr[maxn], n;
bool dfs(int x, int s, int& r){
    if(x == n) return true;
    int nx = arr[x], cr = 0;
    bool status = false;
    r = -1;
    if(dfs(x+1, s, cr)) status = true, r = max(r, cr);
    if(nx + s == (nx | s) && dfs(x+1, nx|s, cr)) status = true, r = max(r, cr+1);
    return status;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(graph, 0, sizeof(graph));memset(arr, 0, sizeof(arr));
    cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(auto c:s) arr[i] |= (1<<(c-'a'));
    }
    int rs;
    dfs(0, 0, rs);
    cout<<rs<<endl;
    return 0;
}

