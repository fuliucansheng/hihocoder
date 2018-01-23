#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int lowbit(int x){
    return x&-x;
}
int main() {
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<n+1;i++) cin>>arr[i];
    int treearr[n+1];
    memset(treearr,0,sizeof(treearr));
    long long res = 0;
    for(int i=n;i>0;i--){
        int num = arr[i];
        while(num <= n){
            treearr[num]++;
            num += lowbit(num);
        }
        num = arr[i] - 1;
        while(num > 0){
            res += treearr[num];
            num -= lowbit(num);
        }
    }
    cout<<res<<endl;
    return 0;
}
