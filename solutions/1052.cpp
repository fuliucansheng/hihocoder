#include <iostream>
#include <map>
#include <vector>
using namespace std;

int g(vector<char> arr){
    map<char,int> count;
    int maxcount = 0;
    for(int i=0;i<arr.size();i++){
        if(count.find(arr[i]) == count.end()) count[arr[i]] = 1;
        else count[arr[i]]++;
        maxcount = max(count[arr[i]],maxcount);
    }
    return arr.size() - maxcount;
}

int main() {
    //freopen("../input.txt","r",stdin);
    int t,k;
    vector<char> tmp;
    string s;
    cin>>t;
    while(t--){
        cin>>s>>k;
        int d=s.size()-k;
        map<int,vector<char>> group;
        for(int i=0;i<min(k,d);i++){
            group[i] = tmp;
            for(int j=i;j<s.size();j+=d) group[i].push_back(s[j]);
        }
        int res = 0;
        for(int i=0;i<min(k,d);i++) res += g(group[i]);
        cout<<res<<endl;
    }
    return 0;
}
