#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1010;
int arr[maxn], n, m, l;
bool is_valid(int x){
    bool rs = false;
    for(int s=n-l+1;s<=n;s++){
        int nm = 0;
        for(int i=0;i<n;i++) if(arr[(s+i)%n] < x) nm++, i += l-1;
        rs |= (nm <= m);
    }
    return rs;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m>>l;
    int mx = 0;
    for(int i=0;i<n;i++) cin>>arr[i], mx = max(mx, arr[i]);
    int lr = 1, rr = mx;
    while(rr - lr > 1){
        int m = (lr + rr)/2;
        if(is_valid(m)) lr = m; else rr = m;
    }
    if(is_valid(rr)) cout<<rr<<endl; else cout<<lr<<endl;
    return 0;
}

