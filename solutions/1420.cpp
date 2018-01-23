#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 205;
int a[maxn], b[maxn], r[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b)); memset(r, 0, sizeof(r));
    string aa, bb; cin>>aa>>bb;
    int la = aa.size(), lb = bb.size();
    for(int i=0;i<la;i++) a[la-i-1] = aa[i] - '0';
    for(int i=0;i<lb;i++) b[lb-i-1] = bb[i] - '0';
    for(int i=0;i<la;i++) for(int j=0;j<lb;j++) r[i+j] += a[i]*b[j];
    for(int i=0;i<maxn-1;i++) r[i+1]+=r[i]/10, r[i]%=10;
    bool s = false;
    for(int i=maxn-1;i>=0;i--){
        if(!s && r[i] != 0) s = true;
        if(s) cout<<r[i];
    }
    if(!s) cout<<0;
    cout<<endl;
    return 0;
}
