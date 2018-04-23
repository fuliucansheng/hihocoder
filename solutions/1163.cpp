#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int arr[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    int s = arr[0];
    for(int i = 1; i < n; i++) s ^= arr[i];
    if(s == 0) cout<<"Bob"<<endl; else cout<<"Alice"<<endl;
    return 0;
}
