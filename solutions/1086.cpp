#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("../input.txt","r",stdin);
    int m, n; cin>>n>>m;
    map<string,int> dict;
    set<int> rec;
    for(int i=1;i<=n;i++){
        string url; cin>>url;
        if(rec.count(dict[url])){
            rec.erase(dict[url]), rec.insert(i);
            dict[url] = i;
            cout<<"Cache"<<endl;
        } else{
            dict[url] = i;
            if(rec.size() == m) rec.erase(rec.begin());
            rec.insert(i);
            cout<<"Internet"<<endl;
        }
    }
    return 0;
}

