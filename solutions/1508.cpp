#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;
const int maxn = 2010;
const double eps = 1e-5;
pii pnt[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int n, r; cin>>n>>r;
    for(int i=0;i<n;i++) cin>>pnt[i].first>>pnt[i].second;
    int ans = 0;
    for(int i=0;i<n;i++){
        vector<pdi> rc;
        for(int j=0;j<n;j++){
            double dx = pnt[j].first - pnt[i].first, dy = pnt[j].second - pnt[i].second;
            double ds = sqrt(dx * dx + dy * dy) / 2;
            if(ds - r > eps) continue;
            double ag1 = atan2(dy, dx), ag2 = acos(ds / r);
            rc.push_back(pdi(ag1 - ag2, 1)); rc.push_back(pdi(ag1 + ag2, -1));
        }
        sort(rc.begin(), rc.end());
        int rs = 0;
        for(auto rr:rc) rs += rr.second, ans = max(ans, rs);
    }
    cout<<ans<<endl;
    return 0;
}
