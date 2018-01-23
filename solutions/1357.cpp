#include <iostream>
using namespace std;
const int maxn = 100010;
int arr[maxn], m, n, k;
bool is_valid(int t){
    int a = 0, b = m;
    for(int i=0;i<n;i++) if(arr[i] >= b) a++, b = m; else b -= arr[i], b += t, b = min(b, m);
    return a < k;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    int l = 1, r = maxn;
    while(r - l > 1){
        int mm = (l + r)/2;
        if(is_valid(mm)) r = mm; else l = mm;
    }
    if(is_valid(l)) cout<<l<<endl;
    else if(is_valid(r)) cout<<r<<endl;
    else cout<<-1<<endl;
    return 0;
}

