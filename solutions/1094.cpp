#include <iostream>
using namespace std;
const int maxn = 300;
char graph[maxn][maxn], round[3][3];
string s;
string gs(int i, int j){
    string res;
    res.push_back(graph[i-1][j-1]);res.push_back(graph[i-1][j]);res.push_back(graph[i-1][j+1]);res.push_back(graph[i][j+1]);
    res.push_back(graph[i+1][j+1]);res.push_back(graph[i+1][j]);res.push_back(graph[i+1][j-1]);res.push_back(graph[i][j-1]);
    return res;
}
string rs(){
    string res;
    res.push_back(round[0][0]);res.push_back(round[0][1]);res.push_back(round[0][2]);res.push_back(round[1][2]);
    res.push_back(round[2][2]);res.push_back(round[2][1]);res.push_back(round[2][0]);res.push_back(round[1][0]);
    return res;
}
bool is_valid(int i, int j){
    if(graph[i][j] != round[1][1]) return false;
    string g1 = gs(i, j);
    string g2 = g1.substr(2) + g1.substr(0,2), g3 = g1.substr(4) + g1.substr(0,4), g4 = g1.substr(6) + g1.substr(0,6);
    return (s == g1 || s == g2 || s == g3 || s == g4);
}
int main(){
    //freopen("../input.txt","r",stdin);
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>graph[i][j];
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>round[i][j];
    s = rs();
    for(int i=1;i<n-1;i++) for(int j=1;j<m-1;j++) if(is_valid(i,j)) cout<<i+1<<" "<<j+1<<endl;
    return 0;
}
