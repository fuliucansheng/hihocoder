#include <iostream>
#include <vector>
using namespace std;
vector<int> nextarr(string patt) {
    vector<int> result(patt.size() + 1, 0);
    for (int i = 1; i < patt.size(); i++) {
        int j = result[i];
        while (j && patt[i] != patt[j]) j = result[j];
        result[i + 1] = patt[i] == patt[j] ? j + 1 : 0;
    }
    return result;
}
bool match(string str, string patt, vector<int> next) {
    int j = 0;
    for (int i = 0; i < str.size(); i++) {
        while (j && str[i] != patt[j]) j = next[j];
        if (str[i] == patt[j]) j++;
        if (j == patt.size()) return true;
    }
    return false;
};

int main(){
    //freopen("../input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        string a,b,c = "";
        int res = 0;
        cin>>a>>b;
        while(c.size() < b.size()) c += a, res++;
        vector<int> next = nextarr(b);
        if(match(c, b, next)) cout<<res<<endl;
        else if(match(c+a, b, next)) cout<<res+1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
