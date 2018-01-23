#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    double a = 1, c;
    for(int i=0;i<n;i++){
        c = 2*a/(i+1);
        a += c;
    }
    cout<<c<<endl;
    return 0;
}
