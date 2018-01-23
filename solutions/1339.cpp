#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
const int maxn = 700;
double arr[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(arr, 0, sizeof(arr));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=6;i++) arr[i] = 1/6.0;
    for(int i=2;i<=n;i++){
        for(int j=6*i;j>=0;j--){
            arr[j] = 0;
            for(int k=1;k<=6;k++) {
                if(j-k >= 0) arr[j] += arr[j-k];
                else break;
            }
            arr[j] /= 6;
        }
        for(int j=i-1;j>=0;j--) arr[j] = 0;
    }
    cout<<fixed<<setprecision(2)<<arr[m]*100<<endl;
    return 0;
}

