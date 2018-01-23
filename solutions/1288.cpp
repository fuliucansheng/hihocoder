#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1050;
int t,n,p,w,h;
int chr[maxn], rec[maxn];
bool is_valid(int fs){
    memset(rec, 0, sizeof(rec));
    int w_c = floor(w/double(fs)), h_c = floor(h/double(fs));
    for(int i=0;i<n;i++) rec[i] = ceil(chr[i]/double(w_c));
    double page = 0;
    for(int i=0;i<n;i++) page += rec[i];
    return ceil(page/h_c) <= p;
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>t;
    while(t--){
        cin>>n>>p>>w>>h;
        for(int i=0;i<n;i++) cin>>chr[i];
        int l = 1, r = min(w,h);
        while(r - l > 1){
            if(is_valid((l+r)/2)) l = (l+r)/2;
            else r = (l+r)/2;
        }
        if(is_valid(r)) cout<<r<<endl;
        else cout<<l<<endl;
    }
    return 0;
}
