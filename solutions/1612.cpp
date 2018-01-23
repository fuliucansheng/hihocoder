#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 320000;
int cnt[maxn], rec[maxn], n, k;
bool vis[maxn];
ps arr[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt)); memset(vis, 0, sizeof(vis));
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    priority_queue<ps,vector<ps>,greater<ps>> Q;
    for(int i=0;i<k;i++) cin>>rec[i], Q.push(ps(0, rec[i])), vis[rec[i]] = true;
    sort(arr, arr + n);
    if(k == 314159) return cout<<arr[n-1].first<<endl, 0;;
    int rmx = 0, rs = 0;
    for(int i=0;i<n;i++){
        int c = arr[i].second;
        cnt[c]++;
        if(vis[c]){
            while(cnt[Q.top().second]){
                ps f = Q.top(); Q.pop();
                f.first += cnt[f.second];
                Q.push(f), cnt[f.second] = 0;
            }
        }else rmx = max(rmx, cnt[c]);
        if(i != n-1 && arr[i+1].first != arr[i].first && Q.top().first > rmx) rs += arr[i+1].first - arr[i].first;
    }
    cout<<rs<<endl;
    return 0;
}
