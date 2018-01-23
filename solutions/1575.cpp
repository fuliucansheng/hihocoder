#include <iostream>
#include <cstring>
#include <map>
using namespace std;
typedef pair<int,int> pos;
int m,n;
char mp[50][50];
map<pair<pos,pos>,int> dt;
void g(pos &o,pos nn){
    if(o.first < 0 || o.second < 0 || o.first >= n || o.second >= m || mp[o.first][o.second] == '1'){
        o.first = nn.first;
        o.second = nn.second;
    }
}
int solve(pos A,pos B){
    if(dt.find(make_pair(A,B)) != dt.end()) return dt[make_pair(A,B)];
    int res = -1;
    if(A == pos(n-1,m-1) && (B == pos(0,0))) res = 0;
    else{
        pos Ar = pos(A.first,A.second+1),Ad = pos(A.first+1, A.second),
                Bl = pos(B.first,B.second-1),Bt = pos(B.first-1, B.second);
        g(Ar,A),g(Ad,A),g(Bl,B),g(Bt,B);
        int r = -1, d = -1;
        if(Ar != B && Ar != Bl && (Ar != A || Bl != B)) r = solve(Ar,Bl);
        if(Ad != B && Ad != Bt && (Ad != A || Bt != B)) d = solve(Ad,Bt);
        if(r != -1 & d != -1) res = 1 + min(r,d);
        else if(r != -1) res = 1 + r;
        else if(d != -1) res = 1 + d;
    }
    dt[make_pair(A,B)] = res;
    return res;
}

int main() {
    //freopen("../input.txt","r",stdin);
    cin>>n>>m;
    memset(mp,1,sizeof(mp));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>mp[i][j];
    int res = solve(pos(0,0),pos(n-1,m-1));
    cout<<res<<endl;
    return 0;
}
