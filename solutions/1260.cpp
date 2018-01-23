#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<string,int> ps;
const int maxn = 10010;
ps sn[maxn];
bool is_valid(string& a, string& b){
    int al = 0, bl = 0, ar = int(a.size()), br = int(b.size());
    while(al < ar && bl < br){
        if((a[al] != b[bl]) && (a[ar] != b[br])) return false;
        if(a[al] == b[bl]) al++, bl++;
        if(a[ar] == b[br]) ar--, br--;
    }
    return true;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int m, n; scanf("%d%d", &n, &m); getchar();
    for(int i=0;i<n;i++) cin>>sn[i].first, sn[i].second = int(sn[i].first.size());
    sort(sn, sn+n, [](ps a, ps b){ return a.second < b.second; });
    for(int i=0;i<m;i++){
        string sm; cin>>sm;
        int ml = int(sm.size()), l = 0, r = n-1;
        while(r - l > 1){
            int mm = (l + r)/2;
            if(sn[mm].second > ml + 1) r = mm;
            else if(sn[mm].second < ml + 1) l = mm;
            else break;
        }
        int rs = 0;
        for(int k=l;k<=r;k++) if(is_valid(sn[k].first, sm)) rs++;
        printf("%d\n", rs);
    }
    return 0;
}
