#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n,w; cin>>n;
    char op;
    vector<int> hp;
    for(int i=0;i<n;i++){
        cin>>op;
        if(op == 'A') cin>>w, hp.push_back(w),push_heap(hp.begin(),hp.end());
        if(op == 'T') pop_heap(hp.begin(),hp.end()), cout<<hp.back()<<endl, hp.pop_back();
    }
    return 0;
}
