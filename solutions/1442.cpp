#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> ps;
set<ps> rec;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    ps arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
        rec.insert(arr[i]);
    }
    ll rs = 10000000000000000;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            ps a = arr[i], b = arr[j];
            ps c = ps(a.first, b.second), d = ps(b.first, a.second);
            if(a.first != b.first && a.second != b.second && rec.find(c) != rec.end() && rec.find(d) != rec.end())
                rs = min(rs, ll(abs(a.first-b.first))*abs(a.second-b.second));
        }
    cout<<(rs==10000000000000000?-1:rs)<<endl;
    return 0;
}
