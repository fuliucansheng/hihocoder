#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, a, b;
    while(cin>>n){
        if(n == -1) break;
        int sm = 0, rs = 0, rc = 0;
        for(int i=0;i<n;i++) {
            cin>>a>>b, rc += (a - b), sm += (a - b);
            if(rc < 0) rs = i + 1, rc = 0;
        }
        if(sm < 0) cout<<-1<<endl; else cout<<rs<<endl;
    }
    return 0;
}

