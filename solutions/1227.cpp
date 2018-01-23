#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define dd(p,q) sqrt((p.first-q.first)*(p.first-q.first) + ((p.second-q.second)*(p.second-q.second)))
typedef pair<double,double> ps;
ps arr[101];
double dis[101][101];
int main(){
    //freopen("../input.txt", "r", stdin);
    int t, m ,n; cin>>t;
    while(t--){
        cin>>m>>n;
        bool s = false;
        int rs = INT32_MAX;
        for(int i=0;i<m;i++) cin>>arr[i].first>>arr[i].second;
        if(n <= m) {
            for(int i=0;i<m;i++) for(int j=i;j<m;j++) dis[i][j] = dis[j][i] = dd(arr[i], arr[j]);
            for(int i=0;i<m;i++){
                sort(dis[i], dis[i]+m);
                int cs = int(ceil(dis[i][n-1]));
                if(cs == dis[i][n-1]) cs++;
                if(n == m || dis[i][n] > cs) rs = min(rs, cs), s = true;
            }
        }
        cout<<((!s || rs == INT32_MAX) ? -1 : rs)<<endl;
    }
    return 0;
}

