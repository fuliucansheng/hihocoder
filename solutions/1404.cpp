#include <bits/stdc++.h>
using namespace std;
char graph[15][15];
bool is_valid(int i,int j){
    bool w = true, wn = true, n = true, en = true, e = true, es = true, s = true, ws = true;
    if(i >= 4) {
        for(int k=0;k<5;k++) if(graph[i-k][j] != graph[i][j]) w = false;
    } else w = false;
    if(i >= 4 && j >= 4) {
        for(int k=0;k<5;k++) if(graph[i-k][j-k] != graph[i][j]) wn = false;
    } else wn = false;
    if(j >= 4) {
        for(int k=0;k<5;k++) if(graph[i][j-k] != graph[i][j]) n = false;
    } else n = false;
    if(i <= 10 && j >= 4) {
        for(int k=0;k<5;k++) if(graph[i+k][j-k] != graph[i][j]) en = false;
    } else en = false;
    if(i <= 10) {
        for(int k=0;k<5;k++) if(graph[i+k][j] != graph[i][j]) e = false;
    } else e = false;
    if(i <= 10 && j <= 10) {
        for(int k=0;k<5;k++) if(graph[i+k][j+k] != graph[i][j]) es = false;
    } else es = false;
    if(j <= 10) {
        for(int k=0;k<5;k++) if(graph[i][j+k] != graph[i][j]) s = false;
    } else s = false;
    if(i >= 4 && j <= 10) {
        for(int k=0;k<5;k++) if(graph[i-k][j+k] != graph[i][j]) ws = false;
    } else ws = false;
    return w|wn|n|en|e|es|s|ws;
}
string solve(){
    int ws = false, bs = false;
    for(int i=0;i<15;i++) {
        for(int j=0;j<15;j++) {
            if(graph[i][j] == 'W' && !ws) ws = ws | is_valid(i,j);
            if(graph[i][j] == 'B' && !bs) bs = bs | is_valid(i,j);
        }
    }
    if(ws && bs) return "Both";
    if(bs) return "Black";
    if(ws) return "White";
    return "None";
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<15;i++) for(int j=0;j<15;j++) cin>>graph[i][j];
        cout<<solve()<<endl;
    }
    return 0;
}
