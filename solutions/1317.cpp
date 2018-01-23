#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 101;
vector<int> r[maxn], c[maxn];
bool vr[maxn], vc[maxn];
int m, n;
bool dfs(int col){
    if(col == m + 1) return true;
    for(auto rr:c[col]) if(!vr[rr]) {
            stack<int> sr, sc;
            for(auto cc:r[rr]) {
                if(!vc[cc]) sc.push(cc), vc[cc] = true;
                for(auto rd:c[cc]) if(!vr[rd]) sr.push(rd), vr[rd] = true;
            }
            int nc = col + 1;
            while(vc[nc]) nc++;
            bool rs = dfs(nc);
            if(rs) return true;
            while(!sr.empty()) vr[sr.top()] = false, sr.pop();
            while(!sc.empty()) vc[sc.top()] = false, sc.pop();
        }
    return false;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        memset(vr, 0, sizeof(vr)); memset(vc, 0, sizeof(vc));
        for(int i=0;i<maxn;i++) r[i].clear(), c[i].clear();
        cin>>n>>m;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
                int num; cin>>num;
                if(num) r[i].push_back(j), c[j].push_back(i);
            }
        bool rs = dfs(1);
        cout<<(rs ? "Yes" : "No")<<endl;
    }
    return 0;
}
