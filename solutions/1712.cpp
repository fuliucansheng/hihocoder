#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
map<char,int> dict;
map<int,char> idct;
vector<int> ss[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<int(s.size());i++) dict[s[i]] = i + 1, idct[i+1] = s[i];
    for(int i=0;i<n;i++){
        cin>>s;
        for(auto c:s) ss[i].push_back(dict[c]);
    }
    sort(ss, ss+n);
    for(int i=0;i<n;i++){
        for(auto c:ss[i]) cout<<idct[c]; cout<<endl;
    }
    return 0;
}
