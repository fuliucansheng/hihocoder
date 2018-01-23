#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5+50;
long long arr[maxn],l[maxn],r[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(l, 0, sizeof(l));memset(r, 0, sizeof(r));
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=1;i<n;i++) l[i] += l[i-1] + (arr[i-1] == 1);
    for(int i=n-1;i>=0;i--) r[i] += r[i+1] + (arr[i+1] == 3);
    long long res = 0;
    for(int i=0;i<n;i++) if(arr[i] == 2) res += l[i]*r[i];
    cout<<res<<endl;
    return 0;
}
