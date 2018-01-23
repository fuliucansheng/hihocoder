#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 2010;
int m, n, arr[maxn], rec[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(rec, -1, sizeof(rec));
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        vector<pair<int,int>> rc;
        int p = 0, s = -1;
        for(int j=i-1;j>=0;j--){
            if(rec[j] != -1) {
                rc.push_back(make_pair(rec[j], rec[j]+arr[j]));
                sort(rc.begin(), rc.end());
                if(rc.size() == 0 || rc[0].first >= arr[i]) rec[i] = 0;
                if(rec[i] == -1) for(int z=1;z<rc.size();z++) if(rc[z].first - rc[z-1].second >= arr[i]) { rec[i] = rc[z-1].second; break; }
                if(rec[i] == -1 && rc.size() > 0) if(m - rc[rc.size()-1].second >= arr[i]) rec[i] = rc[rc.size()-1].second;
                if(rec[i] != -1) p = rec[i], rec[i] = -1; else { rec[i] = p, s = j; break; }
            }
        }
        if(rec[i] == -1) rec[i] = p;
        //for(int j=0;j<i;j++) if(rec[j] >= rec[i] && rec[j] < rec[i] + arr[i]) rec[j] = -1;
        for(int j=s;j>=0;j--) rec[j] = -1;
    }
    for(int i=0;i<n;i++) if(rec[i] != -1) cout<<i+1<<" "<<rec[i]<<endl;
    return 0;
}

