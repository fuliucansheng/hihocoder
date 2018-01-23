#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef pair<int,int> np;
vector<np> num = {np(0,0),np(1,1),np(2,2),np(5,5),np(6,9),np(8,8),np(9,6)};
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
    //freopen("../input.txt","r",stdin);
    for(auto p:num) dict[p.first] = p.second;
    cin>>n;
    for(int i=0;i<=n;i++) if(rec.find(i) == rec.end()) is_valid(i);
    for(auto r:rec) cout<<r<<endl;
    return 0;
}
