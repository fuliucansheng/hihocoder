#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    int l = s[0] - '0', ept;
    string ss = s.substr(1);
    bool status = true, r = true;
    while(ss.size() > 0){
        string n1 = to_string(l+1), n2 = to_string(l+2);
        if(ss.substr(0,n1.size()) == n1) ss = ss.substr(n1.size()), l++;
        else if(status && ss.substr(0,n2.size()) == n2) ss = ss.substr(n2.size()), status = false, ept = l+1, l+=2;
        else{
            r = false;
            break;
        }
    }
    if(r) return cout<<(status ? l+1 : ept), 0;
    l = stoi(s.substr(0,2)), ss = s.substr(2), status = true, r = true;
    while(ss.size() > 0){
        string n1 = to_string(l+1), n2 = to_string(l+2);
        if(ss.substr(0,n1.size()) == n1) ss = ss.substr(n1.size()), l++;
        else if(status && ss.substr(0,n2.size()) == n2) ss = ss.substr(n2.size()), status = false, ept = l+1, l+=2;
        else{
            r = false;
            break;
        }
    }
    cout<<(status ? l+1 : ept)<<endl;
    return 0;
}
