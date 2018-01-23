#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    //freopen("../input.txt","r",stdin);
    int m,n;
    string url;
    cin>>n>>m;
    map<string,int> dict;
    set<int> rec;
    for(int i=1;i<=n;i++){
        cin>>url;
        if(rec.find(dict[url]) != rec.end()){
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

