#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    string s, q, tp;
    cin>>s;
    int n;
    cin>>n;
    map<string,set<int>> endpos;
    map<set<int>,vector<string>> group;
    for(int i=0;i<s.size();i++) for(int j=i;j<s.size();j++) tp = s.substr(i,j-i+1), endpos[tp].insert(j);
    for(auto d:endpos) group[d.second].push_back(d.first);
    for(int i=0;i<n;i++) {
        cin>>q;
        set<int> eps = endpos[q];
        string sht = group[eps][0], lst = group[eps][0];
        for(auto ss:group[eps]) {
            if(ss.size() > lst.size()) lst = ss;
            if(ss.size() < sht.size()) sht = ss;
        }
        cout<<sht<<" "<<lst<<" ";
        for(auto e:eps) cout<<e+1<<" ";
        cout<<endl;
    }
    return 0;
}
