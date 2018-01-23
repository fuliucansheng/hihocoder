#include <iostream>
using namespace std;
bool dfs(int x, int y, int a, int b){
    if(a < x || b < y) return false;
    if(a == x && b == y) return true;
    if(a == b && (a == x || a == y)) return true;
    if(a > b && ((b == y && a%b == x%b) || (b != y && dfs(x, y, a%b, b)))) return true;
    if(a < b && ((a == x && b%a == y%a) || (a != x && dfs(x, y, a, b%a)))) return true;
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        int x, y, a, b; cin>>x>>y>>a>>b;
        cout<<(dfs(x,y,a,b) ? "YES" : "NO")<<endl;
    }
    return 0;
}
