#include <iostream>
#include <cstring>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    string user = "";
    char s[850];
    cin.getline(s,850);
    bool flag = false, start = true;
    for(int i=0;i<strlen(s);i++){
        if(s[i] == '@') {
            if(user.size() > 0) cout<<(start ? "" : " ")<<user, start = false, user = "";
            flag = true;
        }
        else if(flag){
            if(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))) {
                if(user.size() > 0) cout<<(start ? "" : " ")<<user, start = false;
                user = "", flag = false;
            }else user += s[i];
        }
    }
    if(user.size()>0) cout<<(start ? "" : " ")<<user;
    return 0;
}
