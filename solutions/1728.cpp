#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii arr[100010];
int cnt[1000010];
int main() {
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>arr[i].first;
        cnt[arr[i].first]++;
    }
    for(int i = 0; i < n; i++) cin>>arr[i].second;
    set<int> rc;
    for(int i = 1; i <= n + 1; i++) if(cnt[i] == 0) rc.insert(i);
    int ret = *rc.begin();
    for(int i = 0; i < n; i++) {
        if(arr[i].first == arr[i].second) continue;
        cnt[arr[i].first]--, cnt[arr[i].second]++;
        if(cnt[arr[i].second] == 1) {
            rc.erase(arr[i].second);
            if(cnt[arr[i].first] == 0) {
                rc.insert(arr[i].first);
                ret = max(ret, *rc.begin());
                rc.erase(arr[i].first);
            }else ret = max(ret, *rc.begin());
            rc.insert(arr[i].second);
        }else if(cnt[arr[i].first] == 0){
            rc.insert(arr[i].first);
            ret = max(ret, *rc.begin());
            rc.erase(arr[i].first);
        }
        cnt[arr[i].first]++, cnt[arr[i].second]--;
    }
    cout<<ret<<endl;
    return 0;
}
