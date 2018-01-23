#include <iostream>
#include <vector>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    string s, t; cin>>s>>t;
    vector<int> ss, tt;
    for(int i=0;i<int(s.size());i++) if(s[i] != '_') ss.push_back(i);
    for(int i=0;i<int(t.size());i++) if(t[i] != '_') tt.push_back(i);
    if(ss.size() != tt.size()) return cout<<-1<<endl, 0;
    int ans = 0;
    for(int i=0;i<(ss.size());i++){
        int sx = ss[i], tx = tt[i];
        if(s[sx] != t[tx]) return cout<<-1<<endl, 0;
        if(s[sx] == 'L' && sx < tx) return cout<<-1<<endl, 0;
        if(s[sx] == 'R' && sx > tx) return cout<<-1<<endl, 0;
        ans += abs(sx - tx);
    }
    cout<<ans<<endl;
    return 0;
}

