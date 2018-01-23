#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
const int N = 10000;
int group[N];
int groupfind(int x){
    while(group[x] != group[group[x]]) group[x] = group[group[x]];
    return group[x];
}
void groupunion(int x,int y){
    int dx = groupfind(x);
    int dy = groupfind(y);
    if(dx < dy) group[dy] = dx;
    else group[dx] = dy;
}
int main() {
    //freopen("../input.txt","r",stdin);
    int n,c,g;
    cin>>n;
    string users[n],mail;
    for(int i=0;i<n;i++) group[i] = i;
    unordered_map<string,vector<int>> dt;
    vector<int> tp;
    for(int i=0;i<n;i++){
        cin>>users[i]>>c;
        for(int j=0;j<c;j++) {
            cin>>mail;
            if(dt.find(mail) == dt.end()) dt[mail] = tp;
            for(int k=0;k<dt[mail].size();k++) groupunion(dt[mail][k],i);
            dt[mail].push_back(i);
        }
    }
    map<int,vector<int>> rec;
    for(int i=0;i<n;i++){
        g = groupfind(i);
        rec[g].push_back(i);
    }
    for(auto r:rec){
        for(auto out:r.second) cout<<users[out]<<" ";
        cout<<endl;
    }
    return 0;
}
