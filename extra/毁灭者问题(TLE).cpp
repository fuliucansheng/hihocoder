#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct magicunit {
    magicunit(){};
    magicunit(int s,int ms,int rr){
        start = s,maxstore = ms,rerate = rr;
    };
    int start;
    int maxstore;
    int rerate;
};
map<int,vector<int>> dict;
int main() {
    freopen("../input.txt","r",stdin);
    int m,n;
    cin>>n;
    magicunit munits[n];
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        munits[i] = magicunit(a,b,c);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int t,l,r;
        cin>>t>>l>>r;
        r++;
        auto dllr = dict.lower_bound(l),dlrr = dict.lower_bound(r);
        if(dllr != dict.begin()) dllr--;
        if(dlrr != dict.begin()) dlrr--;
        vector<int> timeseq;
        pair<int,vector<int>> rp = make_pair(r,timeseq),lp = make_pair(l,timeseq);
        if(dlrr->first < r) rp.second = dlrr->second;
        if(dllr->first < l) lp.second = dllr->second;
        if(dict.find(l) == dict.end()) dict.insert(lp);
        if(dict.find(r) == dict.end()) dict.insert(rp);
        auto dlr = dict.find(l),drr = dict.find(r);
        for(auto it=dlr;it!=drr;it++){
            it->second.push_back(t);
        }
    }
    int res = 0;
    auto it = dict.begin(),nextit = dict.begin();
    nextit++;
    while(nextit != dict.end()){
        for(int i=0;i<it->second.size();i++){
            int time = it->second[i] - (it->second[i-1]?it->second[i-1]:0);
            for(int j=it->first;j<nextit->first;j++){
                res += min(munits[j-1].maxstore,time*munits[j-1].rerate+munits[j-1].start);
                munits[j-1].start = 0;
            }
        }
        it++,nextit++;
    }
    cout<<res<<endl;
    return 0;
}
