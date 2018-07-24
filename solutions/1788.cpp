#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    string s;
    while(cin>>s) {
        int n = int(s.size());
        bool status = false;
        for(int i = 1; i < n; i++) if(s[i] == s[i - 1]) status = true;
        cout<<(status ? "YES" : "NO")<<endl;
    }
    return 0;
}
