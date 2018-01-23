#include <iostream>
#include <map>
using namespace std;
const int maxn = 100010;
map<int,int> cnt;
int ccnt[maxn], ans[maxn], ac = 0;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        cnt[a]++;
    }
    int mx = 0, rst = n;
    for(auto c:cnt) ccnt[c.second]++, mx = max(mx, c.second);
    bool rs = true;
    while(rst){
        rst--;
        bool f = false;
        for(auto cc:cnt){
            if(ac > 0 && cc.first == ans[ac - 1]) continue;
            int v = cc.first, c = cc.second;
            if(c == mx){
                if(ccnt[c] == 1 && rst >= 2 * (mx - 1)) {
                    f = true, mx--, ans[ac++] = v, cnt[v]--, ccnt[c]--, ccnt[c-1]++;
                    break;
                }
                if(ccnt[c] > 1 && rst >= 2 * mx - 1){
                    f = true, ans[ac++] = v, cnt[v]--, ccnt[c]--, ccnt[c-1]++;
                    break;
                }
            }else if(rst >= (2 * mx - 1)) {
                f = true, ans[ac++] = v, cnt[v]--, ccnt[c]--, ccnt[c-1]++;
                break;
            }
        }
        if(!f) {
            rs = false;
            break;
        } else {
            if(cnt[ans[ac-1]] == 0) cnt.erase(ans[ac-1]);
        }
    }
    if(rs){
        for(int i=0;i<ac;i++) cout<<ans[i]<<" "; cout<<endl;
    }else cout<<-1<<endl;
    return 0;
}
