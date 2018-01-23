#include <iostream>
using namespace std;
const int maxn = 1e5+50;
int stk[maxn], sk = 0;
int main(){
    //freopen("../input.txt","r",stdin);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) if(s[i] == 'h' || s[i] == 'i' || s[i] == 'o') stk[sk++] = i;
    int res = INT32_MAX;
    for(int k=0;k<sk-3;k++){
        int h = (s[stk[k]]=='h') + (s[stk[k+1]]=='h') + (s[stk[k+2]]=='h') + (s[stk[k+3]]=='h');
        int i = (s[stk[k]]=='i') + (s[stk[k+1]]=='i') + (s[stk[k+2]]=='i') + (s[stk[k+3]]=='i');
        int o = (s[stk[k]]=='o') + (s[stk[k+1]]=='o') + (s[stk[k+2]]=='o') + (s[stk[k+3]]=='o');
        if(h == 2 && i == 1 && o == 1) res = min(res, stk[k+3] - stk[k] + 1);
    }
    if(res != INT32_MAX) cout<<res<<endl; else cout<<-1<<endl;
    return 0;
}
