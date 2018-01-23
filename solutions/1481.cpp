#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int n = 0;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int a = 0; bool l = false;
        for(int i=0;i<s.size();i++)
            a += (s[i] == 'A'), l = l || (i<s.size()-2 && s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L');
        if(a <= 1 && !l) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    return 0;
}
