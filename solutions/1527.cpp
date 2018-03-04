#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    string s; cin>>s;
    reverse(s.begin(), s.end());
    vector<int> rc;
    for(int i=0;i<int(s.size());i++) if(s[i] == '1') rc.push_back(i);
    int c = 1, ans = 0;
    for(int i=0;i+1<int(rc.size());i++){
        if(rc[i+1] - rc[i] == 1) c++;
        else{
            if(c > 1) rc[i] = rc[i] + 1, i--;
            c = 1, ans++;
        }
    }
    if(c > 1) ans++;
    cout<<2 * ans + 1<<endl;
    return 0;
}
