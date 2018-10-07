#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int a[maxn], s[maxn], n;
bool vs[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(vs, 0, sizeof(vs)); memset(s, 0, sizeof(s));
    cin>>n;
    map<int,int> mp;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) {
        if(mp.count(a[i])) s[mp[a[i]]] = i;
        mp[a[i]] = i;
    }
    int ans = 0;
    queue<int> Q;
    Q.push(1); vs[1] = true;
    while(!Q.empty()) {
        int qz = int(Q.size());
        for(int i = 0; i < qz; i++) {
            int f = Q.front(); Q.pop();
            if(f == n) return cout<<ans<<endl, 0;
            if(!vs[f + 1]) Q.push(f + 1), vs[f + 1] = true;
            if(s[f] && !vs[s[f]]) Q.push(s[f]), vs[s[f]] = true;
        }
        ans++;
    }
    return 0;
}
