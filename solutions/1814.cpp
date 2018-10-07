#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 100010;
map<int,vector<int>> mpx, mpy;
pii a[maxn];
bool vs[maxn];
set<int> row, col;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i].first>>a[i].second;
        mpx[a[i].first].push_back(i);
        mpy[a[i].second].push_back(i);
    }
    int ans = 0;
    for(auto px : mpx) if(!row.count(px.first)) {
        for(auto x : px.second) if(!vs[x]) {
            queue<int> Q;
            Q.push(x), vs[x] = true;
            int cc = 1;
            while(!Q.empty()) {
                auto f = Q.front(); Q.pop();
                if(!row.count(a[f].first)) {
                    for(auto &pp : mpx[a[f].first]) if(!vs[pp]) Q.push(pp), vs[pp] = true, cc++;
                    row.insert(a[f].first);
                }
                if(!col.count(a[f].second)) {
                    for(auto &pp : mpy[a[f].second]) if(!vs[pp]) Q.push(pp), vs[pp] = true, cc++;
                    col.insert(a[f].second);
                }
            }
            ans += cc - 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
