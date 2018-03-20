#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn = 100010;
set<pll> rc;
ll pos[maxn], group[maxn], len[maxn], dis[maxn], arr[maxn];
ll find_group(ll x){
    if(group[x] == x) return x;
    ll dx = find_group(group[x]);
    dis[x] += dis[group[x]];
    return group[x] = dx;
}
void union_group(ll x, ll y){
    ll dx = find_group(x), dy = find_group(y);
    if(dx == dy) return;
    if(pos[dx] > pos[dy] || (pos[dx] == pos[dy] && dx > dy)) swap(dx, dy);
    dis[dy] = len[dx], len[dx] += len[dy], group[dy] = dx;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n, x = 0; cin>>n;
    for(ll i=1;i<=n;i++) group[i] = i, dis[i] = 0;
    for(ll c=1;c<=n;c++){
        char op; cin>>op;
        if(op == 'I'){
            x++; cin>>pos[x]>>arr[x]; len[x] = arr[x];
            auto p = rc.upper_bound(pll(pos[x], x));
            if(p != rc.begin()) {
                p--;
                if(pos[p->second] + len[p->second] >= pos[x]) union_group(p->second, x);
                else p = rc.insert(pll(pos[x], x)).first;
            }else p = rc.insert(pll(pos[x], x)).first;
            while(true){
                auto pp = p; pp++;
                if(pp == rc.end()) break;
                ll xx = p->second, yy = pp->second;
                if(pos[xx] + len[xx] >= pos[yy]) rc.erase(pp), union_group(xx, yy);
                else break;
            }
        }else{
            ll xx; cin>>xx;
            ll dxx = find_group(xx);
            cout<<pos[dxx] + dis[xx]<<" "<<pos[dxx] + dis[xx] + arr[xx] - 1<<endl;
        }
    }
    return 0;
}
