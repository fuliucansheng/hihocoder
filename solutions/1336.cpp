#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1001, MOD = 1e9+7;
int n, arr[MAXN][MAXN];
int lowbit(int x){ return x&-x; }
void update(int x, int y, int v){
    int nx = x;
    while(nx <= n){
        int ny = y;
        while(ny <= n) arr[nx][ny] += v,ny += lowbit(ny), arr[nx][ny] %= MOD;
        nx += lowbit(nx);
    }
}

int query(int x, int y){
    int sum = 0, nx = x;
    while(nx > 0){
        int ny = y;
        while(ny > 0) sum += arr[nx][ny],ny -= lowbit(ny), sum %= MOD;
        nx -= lowbit(nx);
    }
    return sum;
}

int main(){
    //freopen("../input.txt","r",stdin);
    memset(arr, 0, sizeof(arr));
    int m,x1,x2,y1,y2,v;
    cin>>n>>m;
    string op;
    while(m--){
        cin>>op;
        if(op == "Add"){
            cin>>x1>>y1>>v;
            x1++,y1++;
            update(x1,y1,v);
        }else{
            cin>>x1>>y1>>x2>>y2;
            x1++,y1++,x2++,y2++;
            int res = query(x2, y2) + query(x1-1,y1-1) - query(x2, y1-1) - query(x1-1, y2);
            cout<<(res < 0 ? res + MOD : res)<<endl;
        }
    }
    return 0;
}

