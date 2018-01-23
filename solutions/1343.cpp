#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int maxn = 1e5+10;
vector<int> g1[maxn], g2[maxn];
int deg[maxn], stk[maxn], rec[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(deg, 0, sizeof(deg));memset(stk, 0, sizeof(stk));memset(rec, -1, sizeof(rec));
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int k,m; cin>>k;
        for(int j=0;j<k;j++) cin>>m, g1[m].push_back(i), g2[i].push_back(m), deg[i]++;
    }
    queue<int> Q; Q.push(0);
    stk[++stk[0]] = 0;
    while(!Q.empty()){
        int f = Q.front();Q.pop();
        for(auto v:g1[f]) if(--deg[v] == 0) Q.push(v), stk[++stk[0]] = v;
    }
    rec[0] = 0;
    for(int i=2;i<=stk[0];i++){
        set<int> r;
        int c = 0;
        for(auto v:g2[stk[i]]){
            if(v == 0) rec[stk[i]] = 0;
            else if(rec[v] == 0) c++, r.insert(v);
            else r.insert(rec[v]);
            if(c > 1 || r.size() > 1) {
                rec[stk[i]] = 0;
                break;
            }
        }
        if(rec[stk[i]] == -1) for(auto v:r) rec[stk[i]] = v;
    }
    int rs = 0;
    for(int i=1;i<=n;i++) if(!rec[i]) rs++;
    cout<<rs<<endl;
    return 0;
}
