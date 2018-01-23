#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 35;
int arr[maxn], n, ans = 30;
bool pass(int x, bool s, int i){
    return ((i - x + 1) % 2 == 0) ? (s & (arr[i] > arr[i-1])) : (s ^ (arr[i] > arr[i-1]));
}
void dfs(int x, bool s, int c){
    if(x == n) { ans = min(ans, c); return; }
    if(c < ans && (s ^ (arr[x] > arr[x-1]))) dfs(x+1, !s, c);
    if(c + 1 < ans)
        for(int i=x+1;i<n;i++){
            if(pass(x, s, i)) continue;
            if(s^(arr[i] > arr[x-1])){
                swap(arr[i], arr[x]);
                dfs(x+1, !s, c+1);
                swap(arr[i], arr[x]);
            }
        }
}
void dfs_s(int c){
    if(arr[1] > arr[0]) dfs(2, 1, c);
    for(int i=2;i<n;i++)
        if(arr[i] > arr[0]){
            swap(arr[i], arr[1]);
            dfs(2, 1, c+1);
            swap(arr[i], arr[1]);
        }
}
void dfs_f(int c){
    dfs_s(c);
    for(int i=1;i<n;i++){
        swap(arr[i], arr[0]);
        dfs_s(c+1);
        swap(arr[i], arr[0]);
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    if(n < 3) return cout<<0<<endl, 0;
    for(int i=0;i<n;i++) cin>>arr[i];
    dfs_f(0);
    for(int i=0;i<n;i++) arr[i] *= -1;
    dfs_f(0);
    cout<<ans<<endl;
    return 0;
}
