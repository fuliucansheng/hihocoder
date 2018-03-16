#include <bits/stdc++.h>
using namespace std;
map<char,int> dict;
map<string,int> rec;
void update(string s){
    string r = "";
    for(auto c:s) r += to_string(dict[c]);
    rec[r]++;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    for(int i=0;i<26;i++){
        if(i+'A'<='C') dict[i+'A'] = 2;
        if(i+'A'>='D' && i+'A'<= 'F') dict[i+'A'] = 3;
        if(i+'A'>='G' && i+'A'<= 'I') dict[i+'A'] = 4;
        if(i+'A'>='J' && i+'A'<= 'L') dict[i+'A'] = 5;
        if(i+'A'>='M' && i+'A'<= 'O') dict[i+'A'] = 6;
        if(i+'A'>='P' && i+'A'<= 'S') dict[i+'A'] = 7;
        if(i+'A'>='T' && i+'A'<= 'V') dict[i+'A'] = 8;
        if(i+'A'>='W' && i+'A'<= 'Z') dict[i+'A'] = 9;
    }
    int m,n;
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++) cin>>s, update(s);
    for(int i=0;i<m;i++) cin>>s, cout<<rec[s]<<endl;
    return 0;
}
