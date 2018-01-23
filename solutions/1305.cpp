#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> section;
vector<section> sectionmerge(section arr[],int n){
    vector<section> res;
    int start = arr[0].first,stop = arr[0].second;
    for(int i=1;i<n;i++){
        if(arr[i].first <= stop){
            stop = max(arr[i].second,stop);
        }else{
            res.push_back(section(start,stop));
            start = arr[i].first,stop = arr[i].second;
        }
    }
    if(res.size() == 0 || res[res.size()-1] != section(start,stop)) res.push_back(section(start,stop));
    return res;
}
int restlen(vector<section> Ares,vector<section> Bres){
    int ai = 0,bi = 0,res = 0;
    while(ai < Ares.size()){
        section asec = Ares[ai],bsec;
        if(bi >= Bres.size()) {
            bsec = section(100000001,100000001);
        }else{
            bsec = Bres[bi];
        }
        if(asec.second < bsec.first){
            ai++;
            res += asec.second - asec.first;
        } else if(asec.first <= bsec.first){
            res += bsec.first - asec.first;
            if(bsec.second > asec.second) ai++;
            else bi++,Ares[ai].first = bsec.second;
        } else {
            if(bsec.second > asec.second) ai++;
            else bi++;Ares[ai].first = max(bsec.second,Ares[ai].first);
        }
    }
    return res;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    section A[m],B[n];
    for(int i=0;i<m;i++) cin>>A[i].first>>A[i].second;
    for(int i=0;i<n;i++) cin>>B[i].first>>B[i].second;
    sort(A,A+m),sort(B,B+n);
    vector<section> Ares = sectionmerge(A,m);
    vector<section> Bres = sectionmerge(B,n);
    int res = restlen(Ares,Bres);
    cout<<res<<endl;
    return 0;
}
