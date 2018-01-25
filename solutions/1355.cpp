#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll> nums;
ll m, n;
pll repeat(pll s){
    if(s.second == m) s.second = 1, s.first++;
    else s.second++;
    for(auto num:nums){
        if(s.second + num > m) s.second = num, s.first++;
        else s.second += num;
    }
    return s;
}
int main() {
    //freopen("../input.txt", "r" , stdin);
    cin>>n>>m; cin.get();
    string s; getline(cin, s);
    ll p = 0;
    for(ll i=0;i<=ll(s.size());i++) if(s[i] == ' ' || i == ll(s.size())) nums.push_back(i - p), nums.push_back(1), p = i + 1; nums.pop_back();
    pll r = pll(1,-1);
    map<ll,pll> dict;
    for(ll i=1;i<=n;i++){
        r = repeat(r);
        if(dict.find(r.second) != dict.end()){
            ll rs = (n - i) % (i - dict[r.second].first);
            r.first += (n - i ) / (i - dict[r.second].first) * (r.first - dict[r.second].second);
            for(ll j=0;j<rs;j++) r = repeat(r);
            break;
        }
        dict[r.second] = pll(i, r.first);
    }
    cout<<r.first<<" "<<r.second<<endl;
    return 0;
}
