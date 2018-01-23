#include <iostream>
#include <queue>
using namespace std;
const int maxn = 100010;
int arr[maxn], n;
long long q;
bool is_valid(int k){
    priority_queue<int> Q;
    int a = 0, rec[n], rc = 0;
    while(Q.size() < k) Q.push(arr[a++]);
    while(!Q.empty()) {
        rec[rc++] = Q.top(), Q.pop();
        if(a < n) Q.push(arr[a++]);
    }
    long long rs = 0;
    for(int i=0;i<n;i++) {
        rs += (long long)(i+1)*rec[i];
        if(rs > q) break;
    }
    return rs <= q;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    int l = 1, r = n;
    if(!is_valid(r)) return cout<<-1<<endl, 0;
    while(r - l > 1){
        int m = (l+r)/2;
        if(is_valid(m)) r = m; else l = m;
    }
    cout<<(is_valid(l)?l:r)<<endl;
    return 0;
}
