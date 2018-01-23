#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 105;
map<string,int> dict;
string rec[maxn<<1];
int din[maxn], dout[maxn], cc = 1;
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(din, 0, sizeof(din)); memset(dout, 0, sizeof(dout));
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s, e; cin>>s>>e;
        if(dict.find(s) == dict.end()) rec[cc] = s, dict[s] = cc++;
        if(dict.find(e) == dict.end()) rec[cc] = e, dict[e] = cc++;
        int ds = dict[s], de = dict[e];
        dout[ds]++, din[de]++;
    }
    for(int i=1;i<cc;i++) if(dout[i] > din[i]) { cout<<rec[i]<<" "; break; }
    for(int i=1;i<cc;i++) if(din[i] > dout[i]) { cout<<rec[i]<<" "; break; }
    return 0;
}
