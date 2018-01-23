#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define g(n) graph[n.first][n.second]
#define v(n) visited[n.first][n.second]
#define nt(n) (n.first > 0) ? p(n.first-1, n.second) : p(-1, -1)
#define nb(n) (n.first < nn - 1) ? p(n.first + 1, n.second) : p(-1, -1)
#define nl(n) (n.second > 0) ? p(n.first, n.second-1) : p(-1, -1)
#define nr(n) (n.second < mm - 1) ? p(n.first, n.second + 1) : p(-1, -1)
typedef pair<int,int> p;
const int maxn = 100;
int nn,mm,x,y;
char graph[maxn][maxn];
int visited[maxn][maxn];
bool is_valid(p node){
    return v(node) == 0 && g(node) != '#' && g(node) != 'P';
}
int bfs(int x, int y){
    queue<p> Q;
    int res = 0;
    Q.push(make_pair(x,y));
    while(!Q.empty()){
        res++;
        for(int i=Q.size();i>0;i--){
            p n = Q.front();
            visited[n.first][n.second] = res;
            p t = nt(n),l = nl(n), r = nr(n), b = nb(n);
            if(g(n) == 'S'){
                int rr = INT32_MAX;
                if(g(t) == 'S' && v(t) >= 1) rr = min(rr, res + v(t));
                if(g(l) == 'S' && v(l) >= 1) rr = min(rr, res + v(l));
                if(g(r) == 'S' && v(r) >= 1) rr = min(rr, res + v(r));
                if(g(b) == 'S' && v(b) >= 1) rr = min(rr, res + v(b));
                if(rr != INT32_MAX) return rr - 2;
            }else{
                if(is_valid(t)) Q.push(t);
                if(is_valid(l)) Q.push(l);
                if(is_valid(r)) Q.push(r);
                if(is_valid(b)) Q.push(b);
            }
            Q.pop();
        }
    }
    return -1;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(visited, 0, sizeof(visited));
    cin>>nn>>mm;
    for(int i=0;i<nn;i++)
        for(int j=0;j<mm;j++) {
            cin>>graph[i][j];
            if(graph[i][j] == 'H') x = i, y = j;
        }
    int res = bfs(x, y);
    if(res == -1) cout<<"Hi and Ho will not have lunch."<<endl;
    else cout<<res<<endl;
    return 0;
}
