#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
typedef pair<int,int> section;
int main(){
    //freopen("../input.txt","r",stdin);
    int n,s,e,count = 0;
    set<section> rec;
    priority_queue<int,vector<int>,greater<int>> Q;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>s>>e;rec.insert(section(s,e)); }
    for(auto it:rec){
        if(!Q.empty() && Q.top() > it.first) count++;
        else if(!Q.empty()) Q.pop();
        Q.push(it.second);
    }
    cout<<(count ? count+1 : count)<<endl;
    return 0;
}
