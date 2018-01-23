#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 2010;
string arr[maxn];
int r[maxn][maxn], c[maxn][maxn], m, n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            r[i][j] = ((j > 0 && arr[i][j] != arr[i][j-1]) ? r[i][j-1] + 1 : 1);
            c[i][j] = ((i > 0 && arr[i][j] != arr[i-1][j]) ? c[i-1][j] + 1 : 1);
        }
    int rs = 0;
    for(int i=0;i<n;i++){
        vector<ps> rec;
        for(int j=0;j<m;j++){
            if(j == 0 || r[i][j] == 1) rec.clear();
            int beg = j;
            while(rec.size() != 0 && rec.back().second >= c[i][j]) beg = rec.back().first, rec.pop_back();
            rec.push_back(ps(beg, c[i][j]));
            for(int k=0;k<rec.size();k++) rs = max(rec[k].second*(j-rec[k].first+1), rs);
        }
    }
    cout<<rs<<endl;
    return 0;
}
