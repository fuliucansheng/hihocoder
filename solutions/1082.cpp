#include <bits/stdc++.h>
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
vector<int> match(string str, string patt, vector<int> next) {
    vector<int> result;
    int j = 0;
    for (int i = 0; i < str.size(); i++) {
        while (j && str[i] != patt[j]) j = next[j];
        if (str[i] == patt[j]) j++;
        if (j == patt.size()) result.push_back(i), j = next[j];
    }
    return result;
};

int main(){
    //freopen("../input.txt","r",stdin);
    string patt = "marshtomp", rep = "fjxmlhx";
    vector<int> next = nextarr(patt);
    char str[300];
    while(cin.getline(str, 300)){
        string strcopy = str, dstr = str, strconv = "";
        int start, stop, laststop;
        transform(dstr.begin(), dstr.end(), dstr.begin(), ::tolower);
        vector<int> result = match(dstr, patt, next);
        for(int i=0;i<result.size();i++) {
            start = result[i] - 8, laststop = (i > 0 ? result[i-1] + 1: 0);
            strconv += strcopy.substr(laststop, start - laststop) + rep;
        }
        if(int(result.size()) > 0) strconv += strcopy.substr(result[result.size()-1] + 1);
        else strconv = strcopy;
        cout<<strconv<<endl;
    }
    return 0;
}
