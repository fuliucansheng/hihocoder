#include <bits/stdc++.h>
#define v(x) (x >= 0 && x < n)
using namespace std;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    string arr[n], ans[n];
    for(int i=0;i<n;i++) cin>>arr[i], ans[i] = arr[i];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(arr[i][j] == '.'){
                int c = 0;
                for(int k=0;k<8;k++) if(v(i+dx[k]) && v(j+dy[k]) && arr[i+dx[k]][j+dy[k]] == '*') c++;
                ans[i][j] = char(c + '0');
            }
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;
    return 0;
}

