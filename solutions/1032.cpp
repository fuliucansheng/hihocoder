#include <bits/stdc++.h>
using namespace std;
typedef pair<char,int> pci;
int solve(string s) {
    if (s.size() == 0) return 0;
    vector<pci> rc;
    for(int i=0;i<s.size();i++){
        if(i == 0 || s[i] != s[i-1]) rc.push_back(pci(s[i], 1));
        else rc.back().second++;
    }
    int ret = 1;
    for(int r=0;r<int(rc.size());r++){
        if(r == 0 || r == int(rc.size()-1) || rc[r - 1].first != rc[r + 1].first) ret = max(ret, rc[r].second);
        else{
            int len = rc[r].second, d = 1;
            while((r - d) > 0 && (r + d) < (rc.size() - 1) && rc[r - d] == rc[r + d]) len += 2 * rc[r-d].second, d++;
            if(rc[r-d].first == rc[r+d].first) len += 2 * min(rc[r - d].second, rc[r + d].second);
            if(len > ret) ret = len;
        }
    }
    return ret;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        cout<<solve(s)<<endl;
    }
    return 0;
}