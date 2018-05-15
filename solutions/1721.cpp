#include <bits/stdc++.h>
using namespace std;
string s;
bool is_valid(int x){
    int l = 0, r = int(s.size()) - 1;
    if(l == x) l++;
    if(r == x) r--;
    while(l <= r && s[l] == s[r]) {
        l++, r--;
        if(l == x) l++;
        if(r == x) r--;
    }
    return l > r;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>s;
    int l = 0, r = int(s.size()) - 1;
    while(l <= r && s[l] == s[r]) l++, r--;
    int x;
    if(l > r) x = int(s.size()) / 2;
    else if(is_valid(l)) x = l;
    else x = r;
    while(x > 0 && s[x] == s[x - 1]) x--;
    cout<<x + 1<<endl;
    return 0;
}
