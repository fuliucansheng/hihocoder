#include <iostream>
using namespace std;
string convert(string s){
    string ss = "";
    for(int i=0;i<s.size();i++){
        if(s[i] == '_' && i + 1 < s.size()) ss += toupper(s[i+1]), i++;
        else if(s[i] >= 'A' && s[i] <= 'Z') ss += '_', ss += tolower(s[i]);
        else ss += s[i];
    }
    return ss;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        cout<<convert(s)<<endl;
    }
    return 0;
}
