#include <iostream>
using namespace std;
const int maxn = 101;
int arr[maxn][maxn], m, n;
bool is_valid(int a, int b){
    int s = 0, d = 0;
    for(int i=0;i<3;i++) s += arr[a+i][b+i];
    for(int i=0;i<3;i++) d += arr[a+2-i][b+i];
    if(d!=s) return false;
    for(int i=0;i<3;i++){
        int r = 0;
        for(int j=0;j<3;j++) r += arr[a+i][b+j];
        if(r != s) return false;
    }
    for(int i=0;i<3;i++){
        int r = 0;
        for(int j=0;j<3;j++) r += arr[a+j][b+i];
        if(r != s) return false;
    }
    return true;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    int rs = 0;
    for(int i=0;i<n-2;i++) for(int j=0;j<m-2;j++) rs += is_valid(i,j);
    cout<<rs<<endl;
    return 0;
}
