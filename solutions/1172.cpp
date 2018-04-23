#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int n, s = 0; cin>>n;
    char c;
    for(int i = 0; i < n; i++) {
        cin>>c;
        if(c == 'H') s ^= (i + 1);
    }
    if(s == 0) cout<<"Bob"<<endl; else cout<<"Alice"<<endl;
    return 0;
}
