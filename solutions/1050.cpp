#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
map<int,set<int>> dict;
map<int,int> fdict;
typedef pair<int,int> edge;

void dict2tree(int currnode, int fathernode = 0){
    if(fathernode != 0) fdict[currnode] = fathernode;
    for(auto ch:dict[currnode]){
        if(ch == fathernode) dict[currnode].erase(ch);
        else dict2tree(ch, currnode);
    }
}
int maxdepth(int currnode, int arr[]){
    int res = 0;
    if(arr[currnode] > 0) return arr[currnode];
    for(auto c:dict[currnode]){
        int cdepth = maxdepth(c, arr);
        res = max(res, cdepth);
    }
    res = res + 1;
    arr[currnode] = res;
    return res;
}
int maxinner(int currnode, int arr[], int mxdepth[]){
    int res = 0,fdepth = 0,sdepth = 0;
    if(arr[currnode] > 0) return arr[currnode];
    for(auto c:dict[currnode]){
        int cinner = maxinner(c, arr, mxdepth);
        res = max(res, cinner);
        if(mxdepth[c] > sdepth){
            int fdp = fdepth;
            fdepth = max(fdp, mxdepth[c]);
            sdepth = min(fdp, mxdepth[c]);
        }
    }
    if(dict[currnode].size() > 1) res = max(res,fdepth + sdepth + 2);
    else if(dict[currnode].size() > 0) res = max(res, fdepth + 1);
    arr[currnode] = res;
    return res;
}
int main() {
    //freopen("../input.txt","r",stdin);
    int N,l,r;
    set<int> tmp;
    cin>>N;
    int mxdepth[N+1],mxinner[N+1];
    memset(mxdepth,0,sizeof(mxdepth));
    memset(mxinner,0,sizeof(mxinner));
    for(int i=0;i<N-1;i++){
        cin>>l>>r;
        if(dict.find(l) == dict.end()) dict[l] = tmp;
        if(dict.find(r) == dict.end()) dict[r] = tmp;
        dict[l].insert(r),dict[r].insert(l);
    }
    dict2tree(1);
    int height = maxdepth(1,mxdepth);
    for(int i=0;i<N+1;i++) mxdepth[i]--;
    int res = maxinner(1,mxinner,mxdepth);
    cout<<res<<endl;
    return 0;
}
