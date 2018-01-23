#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<string,string> pp;
const int maxn = 1e5+50;
map<char,int> dict;
pp arr[maxn];
int rtn(string s){
    int r = 0;
    for(int i=s.size()-1;i>=0;i--) if(i == s.size() - 1 || dict[s[i]] >= dict[s[i+1]]) r += dict[s[i]]; else r -= dict[s[i]];
    return r;
}
bool cmp(pp a, pp b){
    if(a.first != b.first) return a.first < b.first;
    return rtn(a.second) < rtn(b.second);
}
int main(){
    //freopen("../input.txt","r",stdin);
    dict['I'] = 1, dict['V'] = 5, dict['X'] = 10, dict['L'] = 50, dict['C'] = 100, dict['D'] = 500, dict['M'] = 1000;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr, arr+n, cmp);
    for(int i=0;i<n;i++) cout<<arr[i].first<<" "<<arr[i].second<<endl;
    return 0;
}
