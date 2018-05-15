#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, m; cin>>n>>m;
    vector<pii> arr;
    for(int i = 0; i < n; i++) {
        set<int> rc;
        for(int j = 0, a; j < m; j++) {
            cin>>a;
            if(!rc.count(a)) arr.push_back(pii(a, i)), rc.insert(a);
        }
    }
    sort(arr.begin(), arr.end());
    int ans = INT32_MAX, cc = 0;
    map<int,int> cnt;
    for(int i=0,j=0;j<int(arr.size());j++){
        if(!cnt.count(arr[j].second)) cc++;
        cnt[arr[j].second]++;
        if(cc >= n){
            while(cnt[arr[i].second] > 1) cnt[arr[i].second]--, i++;
            ans = min(ans, arr[j].first - arr[i].first);
        }
    }
    cout<<ans<<endl;
    return 0;
}
