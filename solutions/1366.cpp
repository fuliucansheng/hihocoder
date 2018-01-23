#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    int rs = 0;
    string s, ss;
    set<string> rec;
    for(int i=0;i<n;i++) {
        cin>>s;
        rec.insert(s), ss.assign(s.rbegin(), s.rend());
        if(rec.find(ss) != rec.end()) rs++;
    }
    cout<<rs<<endl;
    return 0;
}

