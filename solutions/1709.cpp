#include <bits/stdc++.h>
using namespace std;
set<vector<int>> rc;
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        vector<int> ss = { 0 };
        for(int j=1;j<int(s.size());j++) ss.push_back(int(s[j] - s[0] + 26) % 26);
        rc.insert(ss);
    }
    cout<<rc.size()<<endl;
    return 0;
}
