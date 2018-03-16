#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    string s;
    cin>>s;
    stack<int> stk;
    set<pair<int,int>> rec;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(') stk.push(i);
        if(s[i] == ')') rec.insert(make_pair(stk.top()+1, i+1)), stk.pop();
    }
    for(auto r:rec) cout<<r.first<<" "<<r.second<<endl;
    return 0;
}
