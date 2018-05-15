#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int p, q; cin>>p>>q;
    set<int> rc, ans;
    while(!rc.count(p)){
        rc.insert(p), p *= 10;
        ans.insert(p / q), p %= q;
    }
    for(auto a:ans) cout<<a; cout<<endl;
    return 0;
}
