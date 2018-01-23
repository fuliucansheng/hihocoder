#include <iostream>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
map<int,int> dict;
int main(){
    //freopen("../input.txt", "r", stdin);
    int rec[30]; rec[0] = 1, rec[1] = 1; for(int i=2;i<30;i++) rec[i] = rec[i-1] + rec[i-2];
    for(int i=1;i<30;i++) dict[rec[i]] = i;
    int n; cin>>n;
    ll cnt[30], rs = 0; memset(cnt, 0, sizeof(cnt));
    for(int i=0;i<n;i++){
        int a; cin>>a;
        if(a == 1){
            if(!cnt[0]) cnt[0]++, rs++, cnt[0] %= mod, rs %= mod;
            else rs += cnt[0], cnt[1] += cnt[0], cnt[0]++, rs++, rs %= mod, cnt[0] %= mod, cnt[1] %= mod;
        }else if(dict[a]){
            int x = dict[a];
            cnt[x] += cnt[x-1], rs += cnt[x-1], rs %= mod, cnt[x] %= mod;
        }
    }
    cout<<(rs >= 0 ? rs : rs + mod)<<endl;
    return 0;
}

