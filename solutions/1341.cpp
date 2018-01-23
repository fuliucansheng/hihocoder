#include <iostream>
#include <set>
using namespace std;
const int maxn = 25;
int var[26],n,t;
string cons[maxn];
bool is_valid(string s){
    int pre = -1, suf = -1, op = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '=') op = 1;
        else if(s[i] >= '0' && s[i] <= '9'){
            if(suf == -1) suf = s[i] - '0';
            else suf *= 10, suf += s[i] - '0';
        }else if(s[i] == '<'){
            if(op == 0 && pre >= suf) return false;
            if(op == 1 && pre > suf) return false;
            pre = suf, suf = -1, op = 0;
        }
    }
    if(op == 0 && pre >= suf) return false;
    if(op == 1 && pre > suf) return false;
    return true;
}
int main(){
    //freopen("../input.txt","r",stdin);
    char chr;
    cin>>n;
    set<char> rec;
    for(int i=0;i<n;i++) {
        cin>>cons[i];
        for(auto c:cons[i]) if(c >= 'A' && c <= 'Z') rec.insert(c);
    }
    cin>>t;
    while(t--){
        for(int i=0;i<26;i++) var[i] = -1;
        for(int i=0;i<rec.size();i++) {cin>>chr; cin>>var[chr-'A'];}
        bool status = true;
        for(int i=0;i<n;i++){
            string cc = cons[i], cs = "";
            for(int j=0;j<cc.size();j++)
                if(cc[j] >= 'A' && cc[j] <= 'Z') cs += to_string(var[cc[j]-'A']);
                else cs += cc[j];
            if(!is_valid(cs)) status = false;
        }
        if(status) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    }
    return 0;
}
