#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn], b[maxn], c[maxn], m, n, l;
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m>>l;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0;i<l;i++) cin>>c[i];
    sort(a,a+n); sort(b,b+m); sort(c,c+l);
    int aa = 0, bb = 0, cc = 0;
    int rs = 2*(max(a[aa], max(b[bb], c[cc])) - min(a[aa], min(b[bb], c[cc])));
    while(aa < n-1 || bb < m-1 || cc < l-1){
        rs = min(rs, 2*(max(a[aa], max(b[bb], c[cc])) - min(a[aa], min(b[bb], c[cc]))));
        if(a[aa] <= b[bb] && a[aa] <= c[cc]){
            if(aa != n-1) aa++;
            else if(cc == l-1 || (b[bb] <= c[cc])) bb++;
            else cc++;
        }else if(b[bb] <= a[aa] && b[bb] <= c[cc]){
            if(bb != m-1) bb++;
            else if(cc == l-1 || a[aa] <= c[cc]) aa++;
            else cc++;
        }else if(c[cc] <= a[aa] && c[cc] <= b[bb]){
            if(cc != l-1) cc++;
            else if(bb == m-1 || a[aa] <= b[bb]) aa++;
            else bb++;
        }
    }
    cout<<rs<<endl;
    return 0;
}
