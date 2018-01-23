#include <iostream>
#include <cstring>
#include <set>
using namespace std;
const int MAXN = (1<<14)+1;
set<int> edge[14];
int status[14][MAXN],m,n,a,b,res = 0,maxn;
void step(){
    for(int j=0;j<maxn;j++) {
        for (int i=0;i<n;i++) {
            for (auto e:edge[i]) {
                int p = (1<<e)&j, c = (1<<i)&j;
                if (p == 0 && c != 0 && e != i) status[e][(1<<e)|j] += status[i][j];
            }
        }
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(status, 0, sizeof(status));
    cin>>n>>m;
    maxn = (1<<n);
    set<int> rec;
    for(int i=0;i<m;i++) {
        cin>>a>>b, edge[a-1].insert(b-1);
        if(b == 1) rec.insert(a-1);
    }
    status[0][1] = 1;
    step();
    for(auto r:rec) res += status[r][maxn-1];
    cout<<res<<endl;
    return 0;
}
