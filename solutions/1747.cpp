#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int a[maxn], n;
ll ans[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        memset(ans, 0, sizeof(ans));
        vector<int> big, small;
        for(int i = 0; i < n; i++) {
            while(!big.empty() && a[big.back()] < a[i]) big.pop_back();
            while(!small.empty() && a[small.back()] > a[i]) small.pop_back();
            big.push_back(i), small.push_back(i);
            int aa = int(big.size() - 1), bb = int(small.size() - 1);
            while(aa != -1 || bb != -1) {
                if(aa == -1) {
                    ll e = small[bb--];
                    ans[a[big[0]] - a[e]] += e - (bb != -1 ? small[bb] : -1);
                } else if(bb == -1) {
                    ll e = big[aa--];
                    ans[a[e] - a[small[0]]] += e - (aa != -1 ? big[aa] : -1);
                } else {
                    if(big[aa] > small[bb]) {
                        ll e = big[aa--];
                        ans[a[e] - a[small[bb + 1]]] += e - max(small[bb], aa != -1 ? big[aa] : -1);
                    } else if(big[aa] < small[bb]) {
                        ll e = small[bb--];
                        ans[a[big[aa + 1]] - a[e]] += e - max(big[aa], bb != -1 ? small[bb] : -1);
                    } else aa--;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(i) ans[i] += ans[i - 1];
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
