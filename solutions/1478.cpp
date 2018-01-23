#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define r(p) rec[p.first][p.second]
#define vd(p) (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m)
typedef pair<int,int> ps;
const int maxn = 805;
vector<ps> nbr = {ps(-1,0),ps(1,0),ps(0,-1),ps(0,1)};
int rec[maxn][maxn], m, n;
string arr[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(rec, -1, sizeof(rec));
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    queue<ps> Q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(arr[i][j] == '0') rec[i][j] = 0, Q.push(ps(i,j));
    int ds = 1;
    while(!Q.empty()){
        int qz = Q.size();
        while(qz--){
            ps f = Q.front(); Q.pop();
            for(auto nb:nbr){
                ps nr = ps(f.first+nb.first, f.second+nb.second);
                if(vd(nr) && r(nr) == -1) r(nr) = ds, Q.push(nr);
            }
        }
        ds++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<rec[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
