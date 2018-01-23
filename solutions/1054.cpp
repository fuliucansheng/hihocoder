#include <iostream>
#include <cstring>
using namespace std;
int count,n;
int dt[10][10],collect[10][10],nums[10];
bool used[10];
void solve(int curr){
    if(curr > 4){
        int c = 0;
        for(int i=1;i<curr-1;i++) c += collect[nums[i]][nums[i+1]];
        if(c == n) count++;
    }
    for(int i=1;i<10;i++){
        if(!used[i]){
            if(dt[nums[curr-1]][i] && !used[dt[nums[curr-1]][i]]) continue;
            used[i] = true;
            nums[curr] = i;
            solve(curr+1);
            used[i] = false;
        }
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t,l,r;
    cin>>t;
    memset(dt, 0, sizeof(dt));
    dt[1][3] = 2,dt[1][7] = 4,dt[1][9] = 5,dt[2][8] = 5;
    dt[3][7] = 5,dt[3][9] = 6,dt[4][6] = 5,dt[7][9] = 8;
    for(int i = 1;i < 10;i++) for(int j=i+1;j<10;j++) dt[j][i] = dt[i][j];
    while(t--){
        cin>>n;
        memset(collect, 0, sizeof(collect));
        memset(used, 0, sizeof(used));
        for(int i=0;i<n;i++) cin>>l>>r,collect[l][r] = 1,collect[r][l] = 1;
        count = 0;
        solve(1);
        cout<<count<<endl;
    }
    return 0;
}
