#include <iostream>
#include <set>
using namespace std;
#define s(m) (m-2>=0 ? m-2 : m-2+10)
typedef long long ll;
typedef pair<ll,ll> ps;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        ll x, k; cin>>x>>k;
        set<ps> rec;
        ll m = x%10, c = 0;
        ps s = ps(1,m);
        while(rec.find(s) == rec.end()){
            if(s.first == k) break;
            rec.insert(s), s.first = (s.first*s.second)%10, s.second = s(s.second), c++;
        }
        if(s.first == k && 2*c <= x) cout<<x-2*c<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
