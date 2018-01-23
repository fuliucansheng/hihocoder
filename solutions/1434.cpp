#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<string,int> ps;
const int maxn = 105;
ps arr[maxn];
int n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        string s, pre; cin>>s;
        int suf;
        for(int j=0;j<s.size();j++)
            if(s[j] >= '0' && s[j] <= '9') {
                pre = s.substr(0, j), suf = stoi(s.substr(j));
                break;
            }
        arr[i].first = pre, arr[i].second = suf;
    }
    sort(arr, arr+n, [](ps a, ps b){ return a.first != b.first ? a.first < b.first : a.second < b.second; });
    for(int i=0;i<n;i++) cout<<arr[i].first<<arr[i].second<<endl;
    return 0;
}
