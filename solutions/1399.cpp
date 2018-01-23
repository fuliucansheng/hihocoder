#include <iostream>
#include <stack>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, k;
    stack<int> S;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>k;
        if(!S.empty() && (S.top()+k)%2) S.pop(); else S.push(k);
    }
    cout<<S.size()<<endl;
    return 0;
}

