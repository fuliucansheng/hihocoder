#include <iostream>
#include <cstring>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    string str;
    cin>>str;
    int vis[26],res[25],r=0;
    memset(vis, 0, sizeof(vis));memset(res, 0, sizeof(res));
    vis['J'-'A'] = 1;
    for(int i=0;i<str.size();i++) if(str[i] == 'J') str[i] = 'I';
    for(int i=0;i<str.size();i++) if(vis[str[i]-'A'] == 0) res[r++] = str[i]-'A', vis[str[i]-'A'] = 1;
    for(int i=0;i<26;i++) if(vis[i] == 0) res[r++] = i;
    for(int i=0;i<25;i++){
        if(i != 0 && i%5 == 0) cout<<endl;
        cout<<char(res[i]+'A');
    }
    return 0;
}
