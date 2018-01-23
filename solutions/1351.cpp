#include <iostream>
#include <set>
#include <map>
using namespace std;
const int maxn = 1010, maxm = 55;
struct order{
    int n;
    string id[maxm], date[maxm], price[maxm];
}arr[maxn];
map<string,int> dict;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].n;
        set<string> rec;
        for(int j=0;j<arr[i].n;j++) {
            cin>>arr[i].id[j]>>arr[i].date[j]>>arr[i].price[j];
            string ss = arr[i].id[j] + arr[i].price[j];
            if(rec.find(ss) == rec.end()) dict[ss]++, rec.insert(ss);
        }
    }
    for(auto d:dict) if(d.second == n) cout<<d.first.substr(0,9)<<endl;
    return 0;
}

