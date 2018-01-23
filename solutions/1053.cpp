#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> unit;
bool check(vector<unit> rec,int pp,int r){
    int m = 0, store[rec.size()];
    memset(store,0,sizeof(store));
    for(int i=0;i<rec.size();i++){
        if(m >= rec.size() || (rec[m].first - rec[i].first > r)) return false;
        while(rec[i].first - rec[m].first > r) m++;
        if((pp - store[m]) < rec[i].second) rec[i].second -= (pp - store[m]),store[m] = pp,m++,i--;
        else store[m] += rec[i].second,rec[i].second = 0;
    }
    return true;
}
int solve(vector<unit> rec,int r){
    sort(rec.begin(),rec.end(),[](unit a,unit b){ return a.first < b.first; });
    int right = rec[0].second;
    for(int i=0;i<rec.size();i++) right = max(right,rec[i].second);
    int mid = right/2, left = 0;
    while(left != mid){
        if(check(rec,mid,r)) right = mid, mid = (left+right)/2;
        else left = mid+1, mid = (left+right)/2;
    }
    return check(rec,mid,r) ? mid : right;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t,n,r;
    cin>>t;
    while(t--){
        cin>>n>>r;
        vector<unit> rec;
        unit tp;
        for(int i=0;i<n;i++) cin>>tp.first>>tp.second,rec.push_back(tp);
        cout<<solve(rec,r)<<endl;
    }
    return 0;
}
