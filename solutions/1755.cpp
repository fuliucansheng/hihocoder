#include <bits/stdc++.h>
using namespace std;
string dfs(string x, int len) {
    if(len == 1) return string(1, x.back());
    int cc = int(x.length() / len), p = cc - 1;
    while(p >= 0 && x[p] == x[cc - 1]) p--;
    if(p != -1) x = x.substr(0, x.length() - (len - 1) * (p + 1));
    char ch = x[cc - 1];
    x = x.substr(cc);
    string ret = dfs(x, len - 1);
    return ch + ret;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    int n, k; cin>>n>>k;
    string s; cin>>s;
    sort(s.begin(), s.end());
    int len = n / k + (n % k != 0), cc = n % k;
    if(cc) s = s.substr(0, s.length() - (len - 1) * (k - cc));
    else cc = k;
    string ans = dfs(s, len);
    cout<<ans<<endl;
    return 0;
}
