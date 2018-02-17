#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
string arr[maxn], s;
int main() {
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>s;
    unordered_map<char,vector<int>> dict;
    for(int i=0;i<int(s.size());i++) dict[s[i]].push_back(i);
    sort(arr, arr+n, [](string a, string b){ return a.size() > b.size(); });
    for(int i=0;i<n;i++){
        string ss = arr[i];
        bool status = true;
        int p = -1;
        for(auto c:ss) {
            vector<int> pp = dict[c];
            auto r = upper_bound(pp.begin(), pp.end(), p);
            if(r != pp.end()) p = *r;
            else {
                status = false;
                break;
            }
        }
        if(status) return cout<<ss.size()<<endl, 0;
    }
    cout<<0<<endl;
    return 0;
}
