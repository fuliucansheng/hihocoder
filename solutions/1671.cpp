#include <iostream>
#include <stack>
using namespace std;
const int maxn = 5000050;
int rec[maxn];
string s;
void pns(int a, int b, int it = 1){
    if(it == 1){
        for(int i=a;i<=b;i++){
            if(s[i] == '(') pns(i+1, rec[i]-1, -1), i = rec[i];
            else if(s[i] == ')') continue;
            else cout<<s[i];
        }
    }else{
        for(int i=b;i>=a;i--){
            if(s[i] == ')') pns(rec[i]+1, i-1, 1), i = rec[i];
            else if(s[i] == '(') continue;
            else cout<<s[i];
        }
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>s;
    stack<int> stk;
    for(int i=0;i<int(s.size());i++){
        if(s[i] == '(') stk.push(i);
        else if(s[i] == ')') rec[i] = stk.top(), stk.pop(), rec[rec[i]] = i;
    }
    pns(0, int(s.size())-1);
    cout<<endl;
    return 0;
}
