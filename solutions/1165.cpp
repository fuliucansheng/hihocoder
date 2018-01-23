#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 100010;
vector<int> pme = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317};
const int pn = 66;
int cnt[maxn][pn], rec[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(cnt, 0, sizeof(cnt));
    for(int i=1;i<maxn;i++) {
        int r = i;
        for(int j=0;j<pn&&pme[j]<=r;j++) while(r%pme[j] == 0) cnt[i][j]++, r/=pme[j];
    }
    for(int i=1;i<maxn;i++) for(int j=0;j<pn;j++) rec[i] = (j == 0 ? (cnt[i][0] + 1) : rec[i] * (cnt[i][j] + 1));
    int n; cin>>n;
    ps arr[n];
    for(int i=0;i<n;i++) cin>>arr[i].first, arr[i].second = rec[arr[i].first];
    sort(arr, arr+n, [](ps a, ps b){ return a.second > b.second; });
    int nn = min(n, 200), rs = 0;
    for(int i=0;i<nn;i++)
        for(int j=0;j<nn;j++){
            int r = 1;
            for(int k=0;k<pn;k++) r *= (cnt[arr[i].first][k] + cnt[arr[j].first][k] + 1);
            rs = max(rs, r);
        }
    cout<<rs<<endl;
    return 0;
}
