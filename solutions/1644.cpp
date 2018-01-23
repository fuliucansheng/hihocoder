#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int maxn = 50050<<1;
map<string,int> dict;
vector<int> graph[maxn];
vector<bool> vis[maxn];
int din[maxn], dout[maxn];
string r = "", ss, arr[maxn];
int m = 0, ne = 0, n;
void dfs(int x){
    for(int i=0;i<graph[x].size();i++){
        if(!vis[x][i]){
            vis[x][i] = true;
            ne--;
            dfs(graph[x][i]);
        }
    }
    r = arr[x][arr[x].size()-1] + r;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(din, 0, sizeof(din));memset(dout, 0, sizeof(dout));
    cin>>n;
    bool status = true;
    for(int i=0;i<n;i++){
        string pre,suf;
        cin>>ss;
        if(ss.size() == 1) cout<<ss, status = false;
        if(!status) continue;
        pre = ss.substr(0,ss.size()-1), suf = ss.substr(1);
        if(!dict[pre]) dict[pre] = ++m, arr[m] = pre;
        if(!dict[suf]) dict[suf] = ++m, arr[m] = suf;
        int px = dict[pre], sx = dict[suf];
        graph[px].push_back(sx);
        vis[px].push_back(false);
        din[sx]++, dout[px]++;
        ne++;
    }
    if(!status) return 0;
    int deg = 0;
    for(int i=1;i<=m;i++) deg += din[i] - dout[i];
    if(deg != 0) return cout<<"NO"<<endl, 0;
    int ct = 0;
    for(int i=1;i<=m;i++) ct += (din[i] != dout[i]);
    if(!(ct == 0 || ct == 2)) return cout<<"NO"<<endl, 0;
    for(int i=1;i<=m;i++)
        if(dout[i] > din[i]){
            dfs(i);
            r = arr[i].substr(0, arr[i].size()-1) + r;
            if(ne != 0) return cout<<"NO"<<endl, 0;
            return cout<<r<<endl, 0;
        }
    dfs(1);
    r = arr[1].substr(0, arr[1].size()-1) + r;
    if(ne != 0) return cout<<"NO"<<endl, 0;
    cout<<r<<endl;
    return 0;
}
