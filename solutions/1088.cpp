#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
vector<int> graph[maxn];
int hgt[maxn], n;
void dfs(int u){
    for(auto v:graph[u]) if(hgt[v] == -1) dfs(v);
    vector<int> rr;
    for(auto v:graph[u]) rr.push_back(hgt[v]);
    sort(rr.begin(), rr.end(), greater<int>());
    int rs = 1;
    for(int i=0;i<rr.size();i++) rs = max(rs, i+rr[i]);
    hgt[u] = rs;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(hgt, -1, sizeof(hgt));
    cin>>n;
    for(int i=0;i<=n;i++){
        int k, v; cin>>k;
        while(k && cin>>v) if(v != 0) graph[i].push_back(v), k--;
    }
    dfs(0);
    cout<<hgt[0]<<endl;
    return 0;
}
