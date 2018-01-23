#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 100010;
int n, x, y;
ps arr[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>x>>y;
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr, arr+n);
    int rs = 0, nx = x, ny = x;
    bool r = true;
    for(int i=0;i<n;i++){
        if(arr[i].first <= nx) ny = max(ny, arr[i].second);
        else {
            rs++, nx = ny;
            if(nx >= y) break;
            if(arr[i].first > ny) r = false;
        }
    }
    if(ny < y) r = false;
    if(ny >=y && nx < y) rs++;
    if(r) cout<<rs<<endl; else cout<<-1<<endl;
    return 0;
}
