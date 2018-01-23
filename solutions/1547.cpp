#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 205;
int row[maxn][maxn], col[maxn][maxn], m, n, rc;
void rp(ps p, char s, int l, int f, int r){
    if(s == 'l') row[p.first+1][p.second] = l, col[p.first][p.second] = f, row[p.first][p.second] = r;
    if(s == 'r') row[p.first][p.second] = l, col[p.first][p.second+1] = f, row[p.first+1][p.second] = r;
    if(s == 'u') col[p.first][p.second] = l, row[p.first][p.second] = f, col[p.first][p.second+1] = r;
    if(s == 'd') col[p.first][p.second+1] = l, row[p.first+1][p.second] = f, col[p.first][p.second] = r;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(row, 0, sizeof(row)); memset(col, 0, sizeof(col));
    cin>>n>>m;
    rc = 2 * m * n - 1;
    char s = 'd';
    ps p = ps(0, 0);
    for(int i=0;i<rc;i++) {
        int l, f, r; char d;
        cin>>l>>f>>r>>d;
        rp(p, s, l, f, r);
        s = d;
        if(s == 'l') p.second--;
        if(s == 'r') p.second++;
        if(s == 'u') p.first--;
        if(s == 'd') p.first++;
    }
    for(int i=0;i<n+1;i++){
        cout<<"+";
        for(int j=0;j<m;j++) cout<<(row[i][j] ? "-" : " ")<<"+"; cout<<endl;
        if(i != n) for(int j=0;j<m+1;j++) cout<<(col[i][j] ? "|" : " ")<<" "; cout<<endl;
    }
    return 0;
}

