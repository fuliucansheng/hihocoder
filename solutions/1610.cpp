#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    int n; cin>>n;
    cout<<int(ceil(double(n)/2))<<endl;
    for(int i=1;i<=int(ceil(double(n)/2));i++){
        cout<<i<<" ";
        int j;
        for(j=1;j<n/2;j++) cout<<(i - j < 1 ? i - j + n : i - j)<<" "<<(i + j > n ? i + j - n: i + j)<<" ";
        if(n % 2 == 0) cout<<(i - j < 1 ? i - j + n : i - j);
        else cout<<(i - j < 1 ? i - j + n : i - j)<<" "<<(i + j > n ? i + j - n: i + j)<<" ";
        cout<<endl;
    }
    return 0;
}
