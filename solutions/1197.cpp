#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 8192+50;
int main(){
    //freopen("../input.txt","r",stdin);
    char s[maxn];
    while(cin.getline(s, maxn)){
        string str = s;
        char res[maxn];
        memset(res, 0, sizeof(res));
        int c = 0;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        for(int i=0;i<str.size();i++)
            if(str[i] != ' ' || (i > 0 && str[i-1] != ' ')) {
                if((str[i] == ',' || str[i] == '.') && res[c-1] == ' ') res[c-1] = str[i];
                else {
                    if(c == 0 || (c >= 2 && res[c-2] == '.')) res[c++] = toupper(str[i]);
                    else res[c++] = str[i];
                }
            }
        cout<<res<<endl;
    }
    return 0;
}
