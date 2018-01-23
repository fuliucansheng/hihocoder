#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;
map<int,set<int>> dict;
map<int,pair<int,int>> fdict;
vector<int> visit;
void dict2tree(int currnode,int fathernode = 0,int height = 1){
    if(fathernode != 0) fdict[currnode] = make_pair(fathernode,height);
    for(auto ch:dict[currnode]){
        if(ch == fathernode) dict[currnode].erase(ch);
        else dict2tree(ch,currnode,height+1);
    }
}
bool solve(){
    set<int> rec;
    for(int i=visit.size()-1;i>=0;i--){
        int node = visit[i];
        while(node != 1){
            if(rec.find(node) != rec.end()) return false;
            node = fdict[node].first;
        }
        rec.insert(visit[i]);
    }
    int maxheight = 0;
    for(int i=0;i<visit.size();i++) maxheight = max(maxheight,fdict[visit[i]].second);
    for(int j=maxheight;j>0;j--){
        set<int> recmap;
        for(int k=0;k<visit.size();k++){
            if(fdict[visit[k]].second == j){
                visit[k] = fdict[visit[k]].first;
            }
            if(recmap.size() == 0 || visit[k] != visit[k-1]){
                if(recmap.find(visit[k]) != recmap.end()) return false;
                else recmap.insert(visit[k]);
            }
        }
    }
    return true;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t,m,n,v;
    set<int> tmp;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        dict.clear(),visit.clear();
        for(int j=0;j<n-1;j++){
            int n1,n2;
            cin>>n1>>n2;
            if(dict.find(n1) == dict.end()) dict[n1] = tmp;
            if(dict.find(n2) == dict.end()) dict[n2] = tmp;
            dict[n1].insert(n2),dict[n2].insert(n1);
        }
        dict2tree(1);
        cin>>m;
        for(int k=0;k<m;k++) cin>>v,visit.push_back(v);
        bool res = solve();
        cout<<(res?"YES":"NO")<<endl;
    }
    return 0;
}
