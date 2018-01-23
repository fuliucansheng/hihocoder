#include <iostream>
#include <bitset>
using namespace std;
const int maxn = 30010;
int arr[5][maxn], odr[maxn], n;
bitset<maxn> bit[5][maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<5;j++) cin>>arr[j][i];
    for(int i=0;i<5;i++) {
        for(int j=0;j<n;j++) odr[arr[i][j]-1] = j;
        for(int j=1;j<n;j++){
            bit[i][odr[j]] = bit[i][odr[j-1]];
            bit[i][odr[j]][odr[j-1]] = 1;
        }
    }
    for(int i=0;i<n;i++){
        auto rs = bit[0][i];
        for(int j=1;j<5;j++) rs &= bit[j][i];
        cout<<rs.count()<<endl;
    }
    return 0;
}
