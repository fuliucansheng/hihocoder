#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;
pll solve(string s){
    int l = 0, r = 0, n = 0;
    vector<int> rec, tmp;
    for(auto c:s){
        if(c == '(') l++;
        else{
            r++;
            if(r - l > n) n = r - l, tmp.push_back(n), rec.insert(rec.end(), tmp.begin(), tmp.end()), tmp.clear();
            else tmp.push_back(max(0, r - l));
        }
    }
    if(n == 0) return pll(0, 1);
    ll dp[n+1], pre[n+1]; dp[0] = 1;
    for(int i=1;i<=n;i++) dp[i] = 0;
    for(auto rc:rec){
        for(int i=0;i<=n;i++) pre[i] = dp[i] + (i > 0 ? pre[i-1] : 0), pre[i] %= mod;
        for(int i=0;i<=n;i++) dp[i] = (i < rc ? 0 : pre[i]);
    }
    return pll(n, dp[n]);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    string rs = s; reverse(rs.begin(), rs.end());
    for(int i=0;i<int(rs.size());i++) rs[i] = (rs[i] == '(' ? ')' : '(');
    pll r1 = solve(s), r2 = solve(rs);
    cout<<r1.first + r2.first<<" "<<(r1.second * r2.second + mod) % mod<<endl;
    return 0;
}
