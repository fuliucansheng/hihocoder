#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxn = 500000;
map<string,int> dict;
map<int,int> graph[maxn];
int dt = 1, gc = 1;
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    vector<string> arr[n];
    for(int i=0;i<n;i++){
        string s, ss = ""; cin>>s;
        int p = 0;
        for(int j=1;j<s.size();j++){
            if(s[j] == '/'){
                arr[i].push_back(ss);
                if(!dict[ss]) dict[ss] = dt++;
                int ds = dict[ss];
                if(!graph[p][ds]) graph[p][ds] = gc++;
                p = graph[p][ds], ss = "";
            }else ss += s[j];
        }
        arr[i].push_back(ss);
        graph[p][0] = gc++;
    }
    for(int i=0;i<n;i++){
        string rs = "", ss = "";
        int p = 0;
        for(int j=0;j<arr[i].size()-1;j++){
            int ds = dict[arr[i][j]];
            if(graph[p].size() == 1) ss += (ss == "" ? arr[i][j] : "-"+arr[i][j]);
            else rs += (ss != "" ? "/" + ss : ""), ss = arr[i][j];
            p = graph[p][ds];
        }
        if(ss != "") rs += "/" + ss;
        rs += "/" + arr[i][arr[i].size()-1];
        cout<<rs<<endl;
    }
    return 0;
}
