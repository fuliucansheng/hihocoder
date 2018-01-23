#include <iostream>
#include <cmath>
using namespace std;
#define dd(p,q) abs((p/6)-(q/6))+abs((p%6)-(q%6))
int rs[30], w[30][30], b[30];
void iter(int i, int j){
    for(int a=0;a<30;a++) w[j][a] ^= w[i][a];
    b[j] ^= b[i];
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int ct = 0;
    for(int i=0;i<5;i++){
        string s; cin>>s;
        for(auto c:s) b[ct++] = 1^(c-'0');
    }
    for(int i=0;i<30;i++) for(int j=0;j<30;j++) w[i][j] = (dd(i,j) <= 1 ? 1 : 0);
    for(int i=0;i<30;i++) {
        int j= i+1;
        if(w[i][i] == 0) for(j;j<30;j++) if(w[j][i]) { iter(j,i); break;}
        for(j;j<30;j++) if(w[j][i]) iter(i,j);
    }
    int rc = 0;
    for(int i=29;i>=0;i--){
        rs[i] = b[i];
        for(int j=i+1;j<30;j++) if(w[i][j]) rs[i] ^= rs[j];
        if(rs[i]) rc++;
    }
    cout<<rc<<endl;
    for(int i=0;i<30;i++) if(rs[i]) cout<<(i/6+1)<<" "<<(i%6+1)<<endl;
    return 0;
}

