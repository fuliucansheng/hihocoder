#include <bits/stdc++.h>
using namespace std;
map<string,int> dict;
int main(){
    //freopen("../input.txt", "r", stdin);
    dict["red"] = 1, dict["yellow"] = 2, dict["blue"] = 3;
    char ss[1050];cin.getline(ss, 1050);
    string s = ss, c = "";
    stack<int> stk;
    int cnt[4] = {0, 0, 0, 0};
    bool l = false, e = false;
    for(int i=0;i<s.size();i++){
        if(s[i] == '<') l = true;
        if(s[i] == '/') e = true;
        if(s[i] == '>') {
            l = false;
            if(e) stk.pop(), e = false; else stk.push(dict[c]);
            c = "";
        }
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(l) c += s[i];
            else if(!stk.empty()) cnt[stk.top()]++;
        }
    }
    for(int i=1;i<=3;i++) cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}
