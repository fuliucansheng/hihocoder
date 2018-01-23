#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> ps;
const int maxn = 100010;
vector<ps> aa;
ll cnt[maxn];
ll gns(int x){
    int l = 0, r = int(aa.size()-1);
    while(r - l > 1){
        int m = (l + r)/2;
        if(aa[m].first > x) l = m; else r = m;
    }
    if(aa[r].first > x) return cnt[r];
    if(aa[l].first > x) return cnt[l];
    return 0;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        memset(cnt, 0, sizeof(cnt)); aa.clear();
        int m, n, x, y; cin>>n>>m;
        for(int i=0;i<n;i++) {
            cin>>x>>y;
            aa.push_back(ps(x,y));
        }
        sort(aa.begin(), aa.end(), greater<ps>());
        for(int i=0;i<n;i++) cnt[i] = (i > 0 ? cnt[i-1] : 0) + ll(aa[i].second);
        ll rs = 0;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            rs += ll(y) * gns(x);
        }
        cout<<rs<<endl;
    }
    return 0;
}
