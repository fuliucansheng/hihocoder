#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    map<int,int> dict;
    ll ans = 0;
    for(int i=0;i<n;i++){
        int x, y; cin>>x>>y;
        ans += ll(dict[y-x]);
        dict[x-y]++;
    }
    cout<<ans<<endl;
    return 0;
}

