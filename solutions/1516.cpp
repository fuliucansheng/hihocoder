#include <bits/stdc++.h>
using namespace std;
struct node{
    int atk = 0, ctr = 0;
} arr[20];
bool vis[1<<20], go[1<<20], kp[1<<20];
int ship = 0;
int main(){
    //freopen("../input.txt","r",stdin);
    int n, m, a, b, c, x, y; cin>>n>>m>>a>>b>>c;
    for(int i=0;i<a;i++) cin>>x>>y, arr[x].atk |= (1<<y);
    for(int i=0;i<b;i++) cin>>x>>y, arr[y].ctr |= (1<<x);
    for(int i=0;i<c;i++) cin>>x, ship |= (1<<x);
    int s = (1<<n) - 1;
    kp[0] = true, go[0] = false;
    for(int i=1;i<=s;i++){
        bool gs = true, ks = true;
        if(__builtin_popcount(i) > m || (i & ship) == 0) gs = false;
        for(int j=0;j<n;j++) if(i&(1<<j)) if((i&arr[j].atk) && (i&arr[j].ctr) == 0) gs = ks = false;
        go[i] = gs, kp[i] = ks;
    }
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s), vis[s] = true;
    int ans = 0;
    while(!Q.empty()){
        int qz = int(Q.size());
        for(int _=0;_<qz;_++){
            int f = Q.front(); Q.pop();
            int k = f ^ s;
            set<int> nxt;
            for(int i=f;i;i=((i-1)&f)) if(go[i]&&kp[i^f]) nxt.insert(k|i);
            if(nxt.find(s) != nxt.end()) return cout<<ans + 1<<endl, 0;
            for(auto nx:nxt) for(int i=nx;i;i=((i-1)&nx)) if(go[i]&&kp[nx^i]&&!vis[(nx^s)|i]) Q.push((nx^s)|i), vis[(nx^s)|i] = true;
        }
        ans += 2;
    }
    cout<<-1<<endl;
    return 0;
}
