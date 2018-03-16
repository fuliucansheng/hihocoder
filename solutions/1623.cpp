#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> num = {pii(0,0),pii(1,1),pii(2,2),pii(5,5),pii(6,9),pii(8,8),pii(9,6)};
map<int,int> dict;
int n;
set<int> rec;
void is_valid(int m){
    int rm = 0, cm = m, nm;
    while(cm > 0){
        nm = cm % 10;
        if(dict.find(nm) == dict.end()) return;
        if(rm == 0 && nm == 0) return;
        rm *= 10;
        rm += dict[nm];
        cm /= 10;
    }
    if(rm != m && rm <= n) rec.insert(rm), rec.insert(m);
}
int main(){
    //freopen("../ipiiut.txt","r",stdin);
    for(auto p:num) dict[p.first] = p.second;
    cin>>n;
    for(int i=0;i<=n;i++) if(rec.find(i) == rec.end()) is_valid(i);
    for(auto r:rec) cout<<r<<endl;
    return 0;
}
