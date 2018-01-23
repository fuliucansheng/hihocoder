#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int m, n, c = 0;
    cin>>n>>m;
    if(m > n + 1) cout<<"NO";
    else if(m == n + 1) for(int i=0;i<(m+n);i++) cout<<(i%2 == 0 ? 1 : 0);
    else for(int i=0;i<(m+n);i++) cout<<((c < m && i % 2 == 1) ? c++,1 : 0);
    cout<<endl;
    return 0;
}
