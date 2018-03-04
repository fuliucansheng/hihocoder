#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1010;
int arr[maxn], dp[maxn], n, ans = 0;
int get_longest(vector<int> aa){
    memset(dp, 0, sizeof(dp));
    int rr = 0, aaz = int(aa.size());
    for(int i=0;i<aaz;i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++) if(aa[i] < aa[j]) dp[i] = max(dp[i], dp[j] + 1);
        rr = max(rr, dp[i]);
    }
    return rr;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    vector<int> afn, arn;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        if(arr[i] != n) afn.push_back(arr[i]);
    }
    ans = n - get_longest(afn);
    vector<pii> left, right;
    int i = 0;
    for(i;i < n; i++) if(arr[i] == n) break; else left.push_back(pii(arr[i], i));
    for(int j = i + 1; j < n; j++) right.push_back(pii(arr[j], j - i - 1)), arn.push_back(arr[j]);
    sort(left.begin(), left.end(), greater<pii>()); sort(right.begin(), right.end(), greater<pii>());
    int r0 = get_longest(arn);
    ans = min(ans, int(left.size() + right.size()) - r0);
    for(int k=1;k<=int(left.size());k++){
        bool status = true;
        if(k > 1 && left[k-1].second > left[k-2].second) break;
        int std = left[k-1].first, cnt = int(left.size()) - k;
        pii p = pii(INT32_MAX, 0);
        for(int j=0;j<int(right.size());j++){
            auto pp = right[j];
            if(pp.first > std){
                if(pp.second < p.second) status = false;
                if(!status) break;
                p = pp;
            }else{
                if(j == 0) cnt += int(right.size()) - r0;
                else{
                    vector<int> tt;
                    for(int z=right[j-1].second+1;z<int(arn.size());z++) tt.push_back(arn[z]);
                    cnt += int(right.size()) - j - get_longest(tt);
                }
                break;
            }
        }
        if(status) ans = min(ans, cnt);
    }
    cout<<ans<<endl;
    return 0;
}
