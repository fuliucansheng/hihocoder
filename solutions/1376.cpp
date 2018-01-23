#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, a, b;
    while(cin>>n){
        if(n == -1) break;
        for(int i=0;i<n;i++) {
            cin>>b;
            if(i == 0 || b != a) cout<<b<<" ";
            a = b;
        }
        cout<<endl;
    }
    return 0;
}

