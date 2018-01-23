#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1010;
int lt[maxn], rt[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        memset(lt, 0, sizeof(lt)); memset(rt, 0, sizeof(rt));
        for(int i=1;i<s.size();i++) lt[i] = lt[i-1] + (s[i-1] == '1');
        for(int i=s.size()-2;i>=0;i--) rt[i] = rt[i+1] + (s[i+1] == '0');
        int rs = INT32_MAX;
        for(int i=0;i<s.size();i++) rs = min(lt[i]+rt[i], rs);
        cout<<rs<<endl;
    }
    return 0;
}

