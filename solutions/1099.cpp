#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxk = 20;
int m,n,k,h,w;
char s;
vector<pair<int,int>> cons[maxk];
set<pair<int,int>> sky;
bool is_valid(int c, int i, int j){
    for(auto p:cons[c]) if(sky.find(make_pair(p.first+i,p.second+j)) == sky.end()) return false;
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
                if(s == '#') {
                    s_a = min(s_a, a), s_b = min(s_b, b);
                    cons[i].push_back(make_pair(a,b));
                }
            }
        for(int j=0;j<cons[i].size();j++) cons[i][j].first -= s_a, cons[i][j].second -= s_b;
    }
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) { cin>>s;if(s == '#') sky.insert(make_pair(i,j));}
    for(int i=0;i<k;i++) if(search(i)) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    return 0;
}
