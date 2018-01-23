#include <iostream>
using namespace std;
const int maxn = 1010;
int arr[maxn][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, k; cin>>n>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<=k;j++) {
            int p; cin>>p;
            arr[i][p] = j;
        }
    int rs = 0;
    for(int i=k;i>0;i--){
        int cnt = 0;
        for(int j=0;j<n;j++) cnt += int(arr[j][rs] > arr[j][i]);
        if(cnt > n/2) rs = i;
    }
    if(rs > 0) cout<<rs<<endl; else cout<<"otaku"<<endl;
    return 0;
}
