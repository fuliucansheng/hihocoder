#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 55, maxh = 105;
string arr[maxn], ph[maxh];
set<ps> rec[maxh];
int m, n, k, h, w;
vector<int> nextarr(string patt){
    vector<int> result(patt.size() + 1, 0);
    for (int i = 1; i < patt.size(); i++) {
        int j = result[i];
        while (j && patt[i] != patt[j]) j = result[j];
        result[i + 1] = patt[i] == patt[j] ? j + 1 : 0;
    }
    return result;
}
vector<int> match(string str, string patt, vector<int> next){
    int j = 0;
    vector<int> rs;
    for (int i = 0; i < str.size(); i++) {
        while (j && str[i] != patt[j]) j = next[j];
        if (str[i] == patt[j]) j++;
        if (j == patt.size()) rs.push_back(i-patt.size()+1), j = next[j];
    }
    return rs;
};
bool solve(){
    for(int i=0;i<h;i++) rec[i].clear();
    for(int i=0;i<n;i++){
        string s = arr[i];
        while(s.size() < w+4*m) s += arr[i];
        for(int j=0;j<h;j++){
            vector<int> nx = nextarr(ph[j]);
            vector<int> r = match(s, ph[j], nx);
            for(auto rr:r) if(rr < m) rec[j].insert(ps(i,rr));
        }
    }
    for(auto r:rec[0]){
        bool status = true;
        for(int i=1;i<h;i++) if(rec[i].find(ps((r.first+i)%n, r.second)) == rec[i].end()) status = false;
        if(status) return true;
    }
    return false;
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    while(k--){
        cin>>h>>w;
        for(int i=0;i<h;i++) cin>>ph[i];
        cout<<(solve() ? "YES" : "NO")<<endl;
    }
    return 0;
}
