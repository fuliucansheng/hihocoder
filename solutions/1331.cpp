#include <iostream>
using namespace std;

int solve(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else if(n == 2) return 2;
    if((n&1) == 1) return solve((n-1)/2);
    else return solve(n/2)+solve((n-2)/2);
}

int main() {
    //freopen("../input.txt","r",stdin);
    int N;
    cin>>N;
    int res = solve(N);
    cout<<res<<endl;
    return 0;
}
