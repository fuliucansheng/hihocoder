#include <bits/stdc++.h>
using namespace std;
vector<string> get(string s){
    vector<string> ret;
    for(int i = 1; i < int(s.size()); i++) {
        string sp = s.substr(0, i), ss = s.substr(i);
        if(sp.length() > 1 && sp[0] == '0') continue;
        if(ss.length() > 0 && ss.back() == '0') continue;
        ret.push_back(sp + "." + ss);
    }
    if(s.length() == 1 || s.length() > 1 && s[0] != '0') ret.push_back(s);
    return ret;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    set<string> ans;
    for(int i = 1; i < int(s.size()); i++) {
        string sp = s.substr(0, i), ss = s.substr(i);
        vector<string> aa = get(sp), bb = get(ss);
        for(auto a:aa) for(auto b:bb) ans.insert(a + "," + b);
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}
