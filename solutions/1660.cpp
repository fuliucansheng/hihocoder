#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926
typedef pair<int,int> pii;
typedef pair<double,pii> pdii;
pii pv[3], lt[3], rb[3];
int main() {
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        for(int i=0;i<3;i++) cin>>pv[i].first>>pv[i].second;
        for(int i=0;i<3;i++) cin>>lt[i].first>>lt[i].second>>rb[i].first>>rb[i].second;
        int ans = 0, v1[3] = { 0 }, v2[3] = { 0 };
        priority_queue<pdii, vector<pdii>, greater<pdii>> Q;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) {
                    pii a, b, c;
                    if(lt[j].second >= 0){
                        a = lt[j], b = pii(lt[j].first, rb[j].second), c = b;
                        if(rb[j].second >= 0) c = rb[j];
                    }else a = pii(lt[j].first, rb[j].second), b = lt[j], c = pii(rb[j].first, lt[j].second);
                    double aa = atan2(double(a.second), double(a.first)), bb = atan2(double(b.second), double(b.first)), cc = atan2(double(c.second), double(c.first));
                    double pp = double(pv[i].first) / 180 * PI, vv = double(pv[i].second);
                    if(pp >= min(aa, bb) && pp <= max(aa, bb)) Q.push(make_pair(double(b.first) / cos(pp) / vv, pii(i,j)));
                    else if(pp >= min(bb, cc) && pp <= max(bb, cc)) Q.push(make_pair(double(b.second) / sin(pp) / vv, pii(i,j)));
                }
        while(!Q.empty()){
            auto f = Q.top(); Q.pop();
            if(!v1[f.second.first] && !v2[f.second.second]) v1[f.second.first] = v2[f.second.second] = 1, ans++;
        }
        cout<<ans<<endl;
    }
}
