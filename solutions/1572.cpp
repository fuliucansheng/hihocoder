#include <bits/stdc++.h>
using namespace std;
int n, k, a;
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    cin>>n>>k;
    set<int> rc; rc.insert(0), rc.insert(n + 1);
    int ans = -1;
    if(k == n) ans = 0;
    for(int i=1;i<=n;i++){
        cin>>a;
        auto p = rc.insert(a);
        auto pp = p.first, ps = p.first; pp--, ps++;
        if(ans == -1 && (((*ps - a) == (k + 1)) || (a - *pp) == (k + 1))) ans = i;
    }
    cout<<ans<<endl;
    return 0;
}
