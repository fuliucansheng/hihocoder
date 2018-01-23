#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 505;
int l[maxn][maxn], r[maxn][maxn], t[maxn][maxn], b[maxn][maxn], n;
string arr[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(l, 0, sizeof(l)); memset(r, 0, sizeof(r));
    memset(t, 0, sizeof(t)); memset(b, 0, sizeof(b));
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int rs = 0;
    for(int i=0;i<n;i++) for(int j=1;j<n;j++) if(arr[i][j] == '1') l[i][j] = (arr[i][j-1] == '1' ? l[i][j-1] + 1 : 0);
    for(int i=0;i<n;i++) for(int j=n-2;j>=0;j--) if(arr[i][j] == '1') r[i][j] = (arr[i][j+1] == '1' ? r[i][j+1] + 1 : 0);
    for(int i=0;i<n;i++) for(int j=1;j<n;j++) if(arr[j][i] == '1') t[j][i] = (arr[j-1][i] == '1' ? t[j-1][i] + 1 : 0);
    for(int i=0;i<n;i++) for(int j=n-2;j>=0;j--) if(arr[j][i] == '1') b[j][i] = (arr[j+1][i] == '1' ? b[j+1][i] + 1 : 0);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(arr[i][j] == '1') rs = max(min(min(l[i][j],r[i][j]), min(t[i][j],b[i][j])), rs);
    cout<<rs<<endl;
    return 0;
}
