#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2010;
pii aa[maxn], bb[maxn];
int ra[maxn], rb[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, p, q; cin>>n>>p>>q;
    for(int a=0;a<p;a++) cin>>aa[a].first>>aa[a].second>>ra[a];
    for(int b=0;b<q;b++) cin>>bb[b].first>>bb[b].second>>rb[b];
    map<pii,int> rs;
    for(int a=0;a<p;a++) for(int b=0;b<q;b++) if(aa[a].second == bb[b].first) rs[pii(aa[a].first, bb[b].second)] += ra[a]*rb[b];
    for(auto r:rs) if(r.second) cout<<r.first.first<<" "<<r.first.second<<" "<<r.second<<endl;
    return 0;
}
