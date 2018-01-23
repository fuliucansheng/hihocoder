#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        string s, t; cin>>s;
        set<string> rec;
        queue<string> Q; Q.push(s), rec.insert(s);
        t = s, sort(t.begin(), t.end());
        bool status = true;
        int rs = 0;
        while(!Q.empty()){
            int qz = Q.size();
            for(int i=0;i<qz;i++){
                string f = Q.front(); Q.pop();
                if(f == t){ status = false, cout<<rs<<endl; break; }
                for(int j=0;j<f.size()-1;j++){
                    string pre = f.substr(0,j), suf = f.substr(j+2), mid = f.substr(j,2);
                    string rf = pre + suf;
                    for(int k=0;k<=rf.size();k++){
                        string nf = rf.substr(0, k) + mid + rf.substr(k);
                        if(rec.find(nf) == rec.end()) rec.insert(nf), Q.push(nf);
                    }
                }
            }
            if(!status) break;
            rs++;
        }
        if(status) cout<<-1<<endl;
    }
    return 0;
}

