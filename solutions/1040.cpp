#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;
typedef long long ll;
ll get_dis(pii a, pii b){
    ll x = b.first - a.first, y = b.second - a.second;
    return x * x + y * y;
}
bool line_cross(ppp a, ppp b){
    ll da = get_dis(a.first, a.second), db = get_dis(b.first, b.second);
    if(a.first == b.first && (da + db) == get_dis(a.second, b.second)) return true;
    if(a.first == b.second && (da + db) == get_dis(a.second, b.first)) return true;
    if(a.second == b.first && (da + db) == get_dis(a.first, b.second)) return true;
    if(a.second == b.second && (da + db) == get_dis(a.first, b.first)) return true;
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        int cnt = 0;
        ppp arr[4];
        for(int i=0;i<4;i++) cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second.first>>arr[i].second.second;
        for(int i=0;i<4;i++) for(int j=i+1;j<4;j++) if(line_cross(arr[i], arr[j])) cnt++;
        cout<<(cnt == 4 ? "YES" : "NO")<<endl;
    }
    return 0;
}