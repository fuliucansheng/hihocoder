#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, x, maxh, r; cin>>n>>x>>maxh>>r;
    set<pii> rc;
    for(int i = 0; i < r; i++) {
        pii a; cin>>a.first>>a.second;
        if(a.first > a.second) swap(a.first, a.second);
        rc.insert(a);
    }
    int rank[n + 1]; memset(rank, 0, sizeof(rank));
    for(auto a : rc) for(int aa = a.first + 1; aa < a.second; aa++) rank[aa]++;
    int base = maxh + rank[x];
    for(int i = 1; i <= n; i++) cout<<base - rank[i]<<endl;
    return 0;
}
