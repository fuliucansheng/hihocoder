#include <bits/stdc++.h>
using namespace std;

int g(vector<char> arr){
    map<char,int> cnt;
    int mx = 0;
    for(int i=0;i<arr.size();i++) cnt[arr[i]]++, mx = max(cnt[arr[i]], mx);
    return arr.size() - mx;
}

int main() {
    //freopen("../input.txt","r",stdin);
    int t, k; cin>>t;
    string s;
    while(t--){
        cin>>s>>k;
        int d = s.size() - k;
        map<int,vector<char>> group;
        for(int i=0;i<min(k,d);i++) for(int j=i;j<s.size();j+=d) group[i].push_back(s[j]);
        int ans = 0;
        for(int i=0;i<min(k,d);i++) res += g(group[i]);
        cout<<ans<<endl;
    }
    return 0;
}
