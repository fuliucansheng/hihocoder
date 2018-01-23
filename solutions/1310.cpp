#include <iostream>
#include <set>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> pos;
int main() {
    //freopen("../input.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    char arr[m][n],visit[m][n];
    memset(visit,0,sizeof(visit));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    set<set<pos>> dict;
    set<pos> rec;
    queue<pos> Q;
    int num=0;
    for(int i=0;i<m;i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '#' && visit[i][j] == 0) {
                Q.push(pos(0, 0)), rec.clear(), rec.insert(pos(0, 0)), visit[i][j] = 1;
                while (!Q.empty()) {
                    pos f = Q.front();
                    Q.pop();
                    if (i + f.first > 0 && arr[i + f.first - 1][j + f.second] == '#' &&
                        visit[i + f.first - 1][j + f.second] == 0)
                        Q.push(pos(f.first - 1, f.second)),rec.insert(pos(f.first - 1, f.second)), visit[i + f.first - 1][j + f.second] = 1;
                    if (i + f.first < m - 1 && arr[i + f.first + 1][j + f.second] == '#' &&
                        visit[i + f.first + 1][j + f.second] == 0)
                        Q.push(pos(f.first + 1, f.second)),rec.insert(pos(f.first + 1, f.second)),visit[i + f.first + 1][j + f.second] = 1;
                    if (j + f.second > 0 && arr[i + f.first][j + f.second - 1] == '#' &&
                        visit[i + f.first][j + f.second - 1] == 0)
                        Q.push(pos(f.first, f.second - 1)),rec.insert(pos(f.first, f.second-1)),visit[i + f.first][j + f.second - 1] = 1;
                    if (j + f.second < n - 1 && arr[i + f.first][j + f.second + 1] == '#' &&
                        visit[i + f.first][j + f.second + 1] == 0)
                        Q.push(pos(f.first, f.second + 1)),rec.insert(pos(f.first, f.second+1)),visit[i + f.first][j + f.second + 1] = 1;
                }
                num++;
                dict.insert(rec);
            }
        }
    }
    set<int> area;
    for(auto a:dict) area.insert(a.size());
    cout<<num<<" "<<area.size()<<" "<<dict.size()<<endl;
    return 0;
}
