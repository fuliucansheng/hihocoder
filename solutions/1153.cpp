#include <bits/stdc++.h>
using namespace std;
vector<int> dict[10];
void solve(string s){
    bool rec[s.size()];
    memset(rec, 0, sizeof(rec));
    rec[s.size() - 1] = true;
    for(int i = s.size() - 2; i >= 0; i--){
        if(s[i] == s[i+1]) rec[i] = rec[i+1];
        else{
            int c = s[i] - '0', n = s[i+1] - '0';
            if(dict[c][0] <= n) {
                rec[i] = true;
                bool r = false;
                for(auto v : dict[c]) if(n == v) r = true;
                if(!r) rec[i + 1] = false;
            } else rec[i] = false;
        }
    }
    bool status = false;
    int o;
    for(int i = 0; i < s.size(); i++){
        int c = s[i] - '0';
        if(status) cout<<o;
        else{
            if(rec[i]) cout<<c;
            else if(i > 0){
                int p = s[i - 1] - '0', vv;
                for(auto v : dict[p]) if(v < c) vv = v; else break;
                o = dict[vv].back();
                cout<<vv;
                status = true;
            }else{
                int vv = c - 1;
                o = dict[vv].back();
                cout<<vv;
                status = true;
            }
        }
    }
    cout<<endl;
}
int main(){
    //freopen("../input.txt","r",stdin);
    dict[0] = { 0 }; dict[1] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; dict[2] = { 0, 2, 3, 5, 6, 8, 9 };
    dict[3] = { 3, 6, 9 }; dict[4] = { 0, 4, 5, 6, 7, 8, 9 }; dict[5] = { 0, 5, 6, 8, 9 }; dict[6] = { 6, 9 };
    dict[7] = { 0, 7, 8, 9 }; dict[8] = { 0, 8, 9 }; dict[9] = { 9 };
    int n; cin>>n;
    string s;
    for(int i = 0; i < n; i++) {
        cin>>s;
        solve(s);
    }
    return 0;
}
