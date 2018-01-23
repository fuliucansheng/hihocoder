#include <iostream>
#include <cmath>
#include <set>
using namespace std;
typedef pair<int,int> coordinate;
int main(){
    //freopen("../input.txt","r",stdin);
    int p,q;
    cin>>p>>q;
    set<int> ps,qs;
    for(int i=1;i<=ceil(sqrt(p));i++) if(p%i == 0) ps.insert(i), ps.insert(p/i);
    for(int i=1;i<=ceil(sqrt(q));i++) if(q%i == 0) qs.insert(i), qs.insert(q/i);
    set<coordinate> res;
    for(auto psn:ps) for(auto qsn:qs) res.insert(coordinate(psn,qsn));
    for(auto r:res) cout<<r.first<<" "<<r.second<<endl;
    return 0;
}
