#include <iostream>
#include <cmath>
using namespace std;
int k;
string s;
bool is_valid(int p){
    int sx = 0, pc = int(to_string(p).size());
    for(int i=1;i<=p;i++){
        int ic = int(to_string(i).size()); int rc = k - 3 - pc - ic;
        int ex = rc + sx - 1;
        if(ex >= int(s.size()) - 1) return true;
        if(s[ex] != ' ' && s[ex+1] != ' ') while(s[ex] != ' ') ex--;
        sx = ex + 1;
    }
    return false;
}
void pns(int p){
    int sx = 0, pc = int(to_string(p).size());
    for(int i=1;i<=p;i++){
        int ic = int(to_string(i).size()); int rc = k - 3 - pc - ic;
        int ex = rc + sx - 1;
        if(ex < int(s.size()) - 1 && s[ex] != ' ' && s[ex+1] != ' ') while(s[ex] != ' ') ex--;
        cout<<s.substr(sx, ex-sx+1)<<"("<<i<<"/"<<p<<")"<<endl;
        sx = ex + 1;
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>k;
    s = "\n"; getline(cin, s);
    getline(cin, s);
    int l = 1, r = 1;
    while(!is_valid(pow(10,r)-1)) r++;
    l = pow(10, r-1), r = pow(10, r) - 1;
    while(r - l > 1){
        int m = (l + r)/2;
        if(is_valid(m)) r = m; else l = m;
    }
    int p = (is_valid(l) ? l : r);
    pns(p);
    return 0;
}
