#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    vector<int> num = { 2, 3, 5, 7, 23, 37, 53, 73, 373 };
    if(n > num.size()) return cout<<-1<<endl, 0;
    cout<<num[n - 1]<<endl;
    return 0;
}
