#include <bits/stdc++.h>
using namespace std;
int calcStr(string str){
    while(true){
        string str_ = "";
        for(int i=0;i<int(str.size());i++) if(!((i > 0 && str[i] == str[i-1]) || (i + 1 < int(str.size()) && str[i] == str[i+1]))) str_ += str[i];
        if(str_ == str) break;
        str = str_;
    }
    return int(str.size());
}
int solve(string str){
    int ans = 0;
    string A = "A",B = "B", C = "C";
    for(int i=0;i<=int(str.size());i++){
        string pre = str.substr(0, i), suf = str.substr(i);
        string strA = pre + A + suf, strB = pre + B + suf, strC = pre + C + suf;
        int sizeA = calcStr(strA), sizeB = calcStr(strB), sizeC = calcStr(strC);
        int rs = min(sizeA, min(sizeB, sizeC));
        ans = max(ans, int(str.size()) + 1 - rs);
    }
    return ans;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        string str; cin>>str;
        cout<<solve(str)<<endl;
    }
    return 0;
}
