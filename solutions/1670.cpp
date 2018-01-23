#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef pair<int,int> ps;
set<int> mon = {1,3,5,7,8,10,12};
bool is_valid(ps a, ps b){
    if(a.first == b.first) return b.second - a.second > 1;
    if(b.first - a.first == 1){
        if(a.first == 2) return not (a.second == 28 && b.second == 1);
        else if(mon.find(a.first) != mon.end()) return not (a.second == 31 && b.second == 1);
        else return not (a.second == 30 && b.second == 1);
    }
    return true;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        int m, n; cin>>n>>m;
        vector<ps> rec[n+1];
        for(int i=0;i<m;i++){
            int a, b, mm, dd;
            string s; cin>>s>>a>>b;
            sscanf(s.c_str(), "%d-%d", &mm, &dd);
            rec[a].push_back(ps(mm,dd )), rec[b].push_back(ps(mm, dd));
        }
        for(int i=1;i<=n;i++) sort(rec[i].begin(), rec[i].end());
        bool rs = true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<rec[i].size();j++) if(!is_valid(rec[i][j-1], rec[i][j])) { rs = false; break; }
            if(!rs) break;
        }
        cout<<(rs ? "YES" : "NO")<<endl;
    }
    return 0;
}
