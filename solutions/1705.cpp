#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    //freopen("../input.txt","r",stdin);
    int n, m, k; cin>>n>>m>>k;
    int arr[m+2];
    for(int i=1;i<=m;i++) cin>>arr[i];
    arr[0] = 0, arr[m+1] = n+1;
    sort(arr, arr+m+2);
    priority_queue<pii> Q;
    for(int i=1;i<m+2;i++) if(arr[i] - arr[i-1] - 1 > 0) Q.push(pii(arr[i] - arr[i-1] - 1, -(arr[i-1] + 1)));
    for(int i=0;i<k;i++){
        pii f = Q.top(); Q.pop();
        int a = -f.second, b = -f.second + f.first - 1;
        int p = (a + b) / 2;
        if(p - a > 0) Q.push(pii(p - a, -a));
        if(b - p > 0) Q.push(pii(b - p, -(p + 1)));
        cout<<p<<endl;
    }
    return 0;
}
