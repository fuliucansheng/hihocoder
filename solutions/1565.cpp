#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int arr[maxn], n, q;
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cin>>q;
    for(int i=0;i<q;i++){
        int typ, x, y; cin>>typ;
        if(typ == 1){
            cin>>y;
            int ans = 0;
            while(y <= n) y += arr[y], ans++;
            cout<<ans<<endl;
        }else{
            cin>>x>>y;
            arr[x] = y;
        }
    }
    return 0;
}
