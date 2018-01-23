#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef pair<int,char> node;
int main(){
    //freopen("../input.txt", "r", stdin);
    vector<string> r = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    map<string,int> dict;
    for(int i=0;i<r.size();i++) dict[r[i]] = i+1;
    node arr[4];
    for(int i=0;i<4;i++) {
        string s; cin>>s;
        if(s.size() == 2) arr[i].first = dict[s.substr(0,1)];
        if(s.size() == 3) arr[i].first = dict["10"];
        arr[i].second = s[s.size()-1];
    }
    sort(arr, arr+4);
    bool s = true, d = false;
    for(int i=1;i<4;i++) {
        if(arr[i].second != arr[i-1].second) s = false;
        if(arr[i].first == arr[i-1].first) d = true;
    }
    if(d) return cout<<"0/1"<<endl, 0;
    if(arr[0].first == 1){
        if(arr[3].first < 6) return cout<<(s ? "1/16" : "1/12")<<endl, 0;
        arr[0].first = 14, sort(arr,arr+4);
        if(arr[0].first > 9) return cout<<(s ? "1/16" : "1/12")<<endl, 0;
    }else{
        if(arr[3].first - arr[0].first == 4) return cout<<(s ? "1/16" : "1/12")<<endl, 0;
        if(arr[3].first - arr[0].first == 3) return cout<<(s ? "1/8" : "1/6")<<endl, 0;
    }
    cout<<"0/1"<<endl;
    return 0;
}
