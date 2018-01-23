#include <iostream>
using namespace std;
#define r(i,j) ((i>=0 && j>=0) ? rec[i][j] : 0)
typedef long long ll;
const int maxn = 255;
ll arr[maxn][maxn], rec[maxn][maxn], m, n, k;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) rec[i][j] = r(i-1,j) + r(i,j-1) - r(i-1,j-1) + arr[i][j];
    int rs = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            int x = n - 1, y = j;
            while(x >= i && y < m){
                if((r(x,y)-r(i-1,y)-r(x,j-1)+r(i-1,j-1)) <= k) rs = max(rs, (x-i+1)*(y-j+1)), y++;
                else x--;
            }
        }
    }
    cout<<(rs == 0 ? -1 : rs)<<endl;
    return 0;
}
