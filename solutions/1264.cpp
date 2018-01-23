#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int g(string a, string b){
    vector<int> bb[26];
    int rec[a.size()];
    for(int i=int(b.size()-1);i>=0;i--) bb[b[i]-'a'].push_back(i);
    for(int i=0;i<a.size();i++){
        int x = a[i] - 'a';
        if(bb[x].size() == 0) return INT32_MAX;
        rec[i] = bb[x].back(), bb[x].pop_back();
    }
    int rs = 0;
    for(int i=0;i<a.size();i++) for(int j=i+1;j<a.size();j++) if(rec[i] > rec[j]) rs++;
    return rs;
}
int main(){
    //freopen("../input.txt","r",stdin);
    string a, b; cin>>a>>b;
    string c = b;
    int cnt[26]; memset(cnt, 0, sizeof(cnt));
    for(auto chr:a) cnt[chr-'a']++;
    int rs = INT32_MAX, f = -1;
    if(a.size() == b.size()){
        int aa = -1;
        for(int i=0;i<b.size();i++) if(cnt[b[i]-'a']) cnt[b[i]-'a']--; else f = b[i] - 'a';
        for(int i=0;i<26;i++) if(cnt[i]) aa = i;
        if(f != -1) for(int i=0;i<b.size();i++) { if(b[i] == f + 'a') c = b, c[i] = char(aa + 'a'), rs = min(rs, g(a, c)); }
        else rs = min(rs, g(a,b));
    }else{
        if(a.size() > b.size()){
            for(auto chr:b) cnt[chr-'a']--;
            for(int i=0;i<26;i++) if(cnt[i]) f = i;
            for(int i=0;i<=b.size();i++) rs = min(rs, g(a, c.substr(0,i)+char(f+'a')+c.substr(i)));
        }else{
            for(auto chr:b) if(cnt[chr-'a']) cnt[chr-'a']--; else f = chr - 'a';
            for(int i=0;i<b.size();i++) if(b[i] == f + 'a') rs = min(rs, g(a, b.substr(0,i) + b.substr(i+1)));
        }
    }
    cout<<rs<<endl;
    return 0;
}
