#include <iostream>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 105;
int arr[26][maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(arr, 0, sizeof(arr));
    set<int> fib;
    fib.insert(1);
    int a = 1, b = 1, c;
    while(a + b < 100){
        fib.insert(a + b);
        c = a, a = b, b = a + c;
    }
    string s;
    cin>>s;
    set<char> cc;
    set<string> res;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            cc.clear();
            for(int k=i;k<=j;k++) cc.insert(s[k]);
            if(fib.find(cc.size()) != fib.end()) res.insert(s.substr(i,j-i+1));
        }
    }
    for(auto r:res) cout<<r<<endl;
    return 0;
}
