#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n,m;
    cin>>n;
    map<string,string> dict;
    string father,son,son1,son2;
    for(int i=0;i<n;i++) cin>>father>>son,dict[son] = father;
    cin>>m;
    while(m--){
        cin>>son1>>son2;
        set<string> rec;
        while(dict.find(son1) != dict.end()) rec.insert(son1),son1 = dict[son1];
        rec.insert(son1);
        bool status = false;
        while(dict.find(son2) != dict.end()) {
            if(rec.find(son2) != rec.end()){
                cout<<son2<<endl;
                status = true;
                break;
            }
            son2 = dict[son2];
        }
        if(!status && rec.find(son2) != rec.end()) cout<<son2<<endl,status = true;
        if(!status) cout<<-1<<endl;
    }
    return 0;
}
