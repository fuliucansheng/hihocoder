#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 1e5;
int value[N+1],tree[N+1],store[N+1];
map<int,vector<int>> dt;
void build(int node){
    int res = value[node];
    for(int i=0;i<dt[node].size();i++){
        build(dt[node][i]);
        res = min(store[dt[node][i]], res);
    }
    store[node] = res;
}

bool update(int node){
    int res = value[node];
    for(int i=0;i<dt[node].size();i++) res = min(store[dt[node][i]], res);
    bool status = (store[node] == res);
    store[node] = res;
    return status;
}
int main() {
    //freopen("../input.txt","r",stdin);
    int n,q,t,nd,v;
    cin>>n;
    vector<int> vec;
    for(int i=1;i<=n;i++) cin>>value[i];
    for(int i=2;i<=n;i++){
        cin>>tree[i];
        if(dt.find(tree[i]) == dt.end()) dt[tree[i]] = vec;
        dt[tree[i]].push_back(i);
    }
    build(1);
    cin>>q;
    while(q--){
        cin>>t>>nd;
        if(t == 1){
            cin>>v;
            value[nd] = v;
            int curr = nd;
            while(true){
                bool s = update(curr);
                if(s || curr == 1) break;
                curr = tree[curr];
            }
        }else{
            cout<<store[nd]<<endl;
        }
    }
    return 0;
}
