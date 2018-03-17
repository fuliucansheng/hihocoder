#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxk = 20;
int m, n, k, h, w;
char s;
vector<pii> cons[maxk];
set<pii> sky;
bool is_valid(int c, int i, int j){
    for(auto p:cons[c]) if(!sky.count(pii(p.first+i,p.second+j))) return false;
    return true;
}
bool search(int c){
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(is_valid(c,i,j)) return true;
    return false;
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>h>>w;
        int s_a = h, s_b = w;
        for(int a=0;a<h;a++) for(int b=0;b<w;b++) {
                cin>>s;
                if(s == '#') s_a = min(s_a, a), s_b = min(s_b, b), cons[i].push_back(pii(a,b));
            }
        for(auto& v:cons[i]) v.first -= s_a, v.second -= s_b;
    }
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
            cin>>s;
            if(s == '#') sky.insert(make_pair(i,j));
        }
    for(int i=0;i<k;i++) cout<<(search(i) ? "Yes": "No")<<endl;
    return 0;
}
