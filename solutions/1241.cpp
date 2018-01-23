#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 1010, maxv = 1e6+10;
int arr[maxn][maxn], dp2[maxn][maxn], dp5[maxn][maxn], t[maxv], f[maxv], n;
void ft(int v){
    int vv = v;
    while(vv > 0){
        if(vv%10 == 0) vv /= 10, t[v]++, f[v]++;
        else if(vv%2 == 0) vv /= 2, t[v]++;
        else if(vv%5 == 0) vv /= 5, f[v]++;
        else break;
    }
}
void dpt(){
    for(int i=n-1;i>=0;i--)
        for(int j=n-1;j>=0;j--)
            if(i == n-1 && j == n-1) dp2[i][j] = t[arr[i][j]];
            else{
                dp2[i][j] = INT32_MAX;
                if(i < n-1 && arr[i+1][j]) dp2[i][j] = min(dp2[i][j], dp2[i+1][j]);
                if(j < n-1 && arr[i][j+1]) dp2[i][j] = min(dp2[i][j], dp2[i][j+1]);
                if(arr[i][j] && dp2[i][j] != INT32_MAX) dp2[i][j] += t[arr[i][j]];
            }
}
void dpf(){
    for(int i=n-1;i>=0;i--)
        for(int j=n-1;j>=0;j--)
            if(i == n-1 && j == n-1) dp5[i][j] = f[arr[i][j]];
            else{
                dp5[i][j] = INT32_MAX;
                if(i < n-1 && arr[i+1][j]) dp5[i][j] = min(dp5[i][j], dp5[i+1][j]);
                if(j < n-1 && arr[i][j+1]) dp5[i][j] = min(dp5[i][j], dp5[i][j+1]);
                if(arr[i][j] && dp5[i][j] != INT32_MAX) dp5[i][j] += f[arr[i][j]];
            }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(t, 0, sizeof(t));memset(f, 0, sizeof(f));
    for(int i=1;i<maxv;i++) ft(i);
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    dpt();dpf();
    cout<<min(dp5[0][0], dp2[0][0])<<endl;
    return 0;
}
