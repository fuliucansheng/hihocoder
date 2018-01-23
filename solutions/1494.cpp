#include <iostream>
#include <map>
using namespace std;
map<int,int> dict;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, rs = 0; cin>>n;
    for(int i=0;i<n;i++){
        int c, m, e = 0; cin>>c;
        for(int j=0;j<c;j++) {
            cin>>m;
            if(j != c - 1) e += m, dict[e]++, rs = max(rs, dict[e]);
        }
    }
    cout<<(n - rs)<<endl;
    return 0;
}
