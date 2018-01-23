#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> nbr = { pii(-1,0), pii(1,0), pii(0,-1), pii(0,1) };
const ll maxn = 900000000;
unordered_set<ll> vis;
ll get_status(ll arr[9]){
    ll rs = 0;
    for(int i=0;i<9;i++) rs += arr[i], rs *= 10;
    return rs / 10;
}
vector<ll> get_nbr(ll s){
    vector<ll> rs;
    ll arr[9], p;
    for(int i=8;i>=0;i--) {
        arr[i] = (s % 10), s /= 10;
        if(arr[i] == 0) p = i;
    }
    ll x = p / 3, y = p % 3;
    for(auto nb:nbr){
        ll nx = x + nb.first, ny = y + nb.second;
        if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
            ll np = 3 * nx + ny;
            swap(arr[p], arr[np]);
            rs.push_back(get_status(arr));
            swap(arr[p], arr[np]);
        }
    }
    return rs;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int _, t = 123456780; cin>>_;
    while(_--){
        ll arr[9]; vis.clear();
        for(int i=0;i<9;i++) cin>>arr[i];
        ll s = get_status(arr);
        queue<ll> Q;
        Q.push(s), vis.insert(s);
        ll rs = 0;
        bool status = false;
        while(!Q.empty()){
            int qz = int(Q.size());
            for(int i=0;i<qz;i++){
                ll f = Q.front(); Q.pop();
                if(f == t) { status = true; break; }
                vector<ll> nb = get_nbr(f);
                for(auto nr:nb) if(vis.find(nr) == vis.end()) Q.push(nr), vis.insert(nr);
            }
            if(status) break;
            rs++;
        }
        if(status) cout<<rs<<endl; else cout<<"No Solution!"<<endl;
    }
    return 0;
}
