#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    //freopen("../input.txt","r",stdin);
    int n,c;
    cin>>n;
    string user[n],mail;
    int group[n];
    unordered_map<string,int> dt;
    for(int i=0;i<n;i++) group[i] = i;
    for(int i=0;i<n;i++){
        cin>>user[i]>>c;
        for(int j=0;j<c;j++) {
            cin >> mail;
            if (dt.find(mail) == dt.end()) dt[mail] = i;
            else {
                while (dt[mail] != group[dt[mail]]) dt[mail] = group[dt[mail]];
                group[dt[mail]] = i;
            }
        }
    }
    set<int> rec;
    for(int i=n-1;i>=0;i--) while(group[i] != group[group[i]]) group[i] = group[group[i]];
    for(int i=0;i<n;i++){
        if(rec.find(i) == rec.end()){
            int out = i;
            while(out < n) {
                if(group[out] == group[i]) cout<<user[out]<<" ",rec.insert(out);
                out++;
            }
            cout<<endl;
        }
    }
    return 0;
}
