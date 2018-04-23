#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    long long n, k, v, c = 0;
    scanf("%lld%lld", &n, &k);
    bool s = false;
    for(long long i=0;i<n;i++){
        scanf("%lld", &v);
        if(v < k) c++;
        if(v == k) s = true;
    }
    cout<<(s ? c+1 : -1)<<endl;
    return 0;
}
