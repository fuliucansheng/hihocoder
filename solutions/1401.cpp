#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 10010, maxm = 101;
struct student{
    ll no, t, p, ans = 0;
    vector<pll> ow;
} stu[maxn];
struct job{
    ll j, s, t, x;
    job(){}
    job(ll jj, ll ss, ll tt, ll xx):j(jj), s(ss), t(tt), x(xx){}
    bool operator < (const job b) const{
        if(t != b.t) return t > b.t;
        return stu[s].no > stu[b.s].no;
    }
};
int main() {
    //freopen("../input.txt", "r", stdin);
    ll n, m, k; cin>>n>>m>>k;
    ll t[maxm]; memset(t, 0, sizeof(t));
    for(ll i=0;i<n;i++){
        cin>>stu[i].no>>stu[i].t>>stu[i].p;
        ll o, w;
        for(ll j=0;j<stu[i].p;j++) {
            cin>>o>>w;
            stu[i].ow.push_back(pll(o, w));
        }
    }
    priority_queue<job> pq;
    for(ll i=0;i<n;i++) if(stu[i].p > 0) pq.push(job(stu[i].ow[0].first, i,  stu[i].t + k, 0)), stu[i].ans = stu[i].t + k;
    while(!pq.empty()){
        job f = pq.top(); pq.pop();
        t[f.j] = max(t[f.j], f.t) + stu[f.s].ow[f.x].second;
        stu[f.s].ans = t[f.j];
        if(stu[f.s].p > f.x + 1) {
            if(stu[f.s].ow[f.x].first != stu[f.s].ow[f.x + 1].first) pq.push(job(stu[f.s].ow[f.x + 1].first, f.s, stu[f.s].ans + k, f.x + 1));
            else pq.push(job(stu[f.s].ow[f.x + 1].first, f.s, stu[f.s].ans, f.x + 1));
        }
    }
    for(ll i=0;i<n;i++) cout<<stu[i].ans<<endl;
    return 0;
}
