#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    priority_queue<int> pq;
    for(int i = 0, x; i < n; i++) cin>>x, pq.push(x);
    ll ans = 0;
    while(pq.size() > 1) {
        int f = pq.top(); pq.pop();
        int s = pq.top(); pq.pop();
        if(f > s) {
            ans += s, f -= s;
            if(f) pq.push(f);
        } else {
            ans += f, s -= f;
            if(s) pq.push(s);
        }
    }
    cout<<ans<<endl;
    return 0;
}
