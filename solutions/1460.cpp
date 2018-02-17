#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("../input.txt", "r", stdin);
    int k; cin>>k;
    string s, r = ""; cin>>s;
    vector<int> rec[26];
    for(int i=0;i<int(s.size());i++) rec[s[i]-'a'].push_back(i);
    int sz = int(s.size()), p = -1;
    while(k){
        bool status = false;
        for(int i=0;i<26;i++){
            auto pp = upper_bound(rec[i].begin(), rec[i].end(), p);
            if(pp == rec[i].end()) continue;
            if((sz - *pp) >= k) r += char('a' + i), k--, p = *pp, status = true;
            if(status) break;
        }
        if(!status) break;
    }
    cout<<r<<endl;
}
