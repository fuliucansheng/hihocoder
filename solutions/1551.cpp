#include <iostream>
#include <map>
using namespace std;
const int maxn = 500000;
map<string,int> dict;
map<int,int> graph[maxn];
int dt = 1, gc = 1;
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    int rs = 0;
    for(int i=0;i<n;i++){
        string s, ss = ""; cin>>s;
        int p = 0;
        for(int j=1;j<s.size();j++) {
            if(s[j] == '/'){
                if(!dict[ss]) dict[ss] = dt++;
                int ds = dict[ss];
                if(!graph[p][ds]) graph[p][ds] = gc++, rs++;
                p = graph[p][ds];
                ss = "";
            }else ss += s[j];
        }
    }
    cout<<rs<<endl;
    return 0;
}

