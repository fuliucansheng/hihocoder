#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct task {
    int info[7];
    bool operator < (task &b) {
        return info[6] > b.info[6];
    }
} a[10010];
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    map<int,string> conv_mp = {{0, "CV"}, {1, "DD"}, {2, "CL"}, {3, "CA"}, {4, "BB"}, {5, "BC"}};
    map<string,int> icov_mp;
    for(auto p : conv_mp) icov_mp[p.second] = p.first;
    while(t--) {
        int n, m; cin>>n>>m;
        map<int,vector<pii>> mp;
        for(int i = 0; i < n; i++) {
            string tp; cin>>tp;
            int l, f; cin>>l>>f;
            mp[icov_mp[tp]].push_back(pii(l, f));
        }
        for(auto &p : mp) sort(p.second.begin(), p.second.end());
        for(int i = 0; i < m; i++) for(int j = 0; j < 7; j++) cin>>a[i].info[j];
        sort(a, a + m);
        ll ret = 0;
        bool status = true;
        priority_queue<int,vector<int>,greater<int>> pq[6];
        for(int i = 0; i < m; i++) {
            int g = a[i].info[6];
            for(auto &p : mp) while(!p.second.empty() && p.second.back().first >= g) pq[p.first].push(p.second.back().second), p.second.pop_back();
            for(int j = 0; j < 6; j++) {
                while(a[i].info[j] && !pq[j].empty()) ret += pq[j].top(), pq[j].pop(), a[i].info[j]--;
                if(a[i].info[j]) {
                    status = false;
                    break;
                }
            }
            if(!status) break;
        }
        cout<<(status ? ret : -1)<<endl;
    }
    return 0;
}
