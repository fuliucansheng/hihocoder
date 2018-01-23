#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> ps;
const int maxn = 10010;
int amt[maxn], val[maxn], mtk[maxn], ac = 0, m, n;
ps arr[maxn<<1];
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>amt[i];
    for(int i=0;i<m;i++) cin>>val[i];
    for(int i=0;i<m;i++) cin>>mtk[i];
    for(int i=0;i<m;i++){
        int c = amt[i]/mtk[i], r = amt[i]%mtk[i];
        if(c) arr[ac].first = val[i]*mtk[i], arr[ac].second = c, ac++;
        if(r) arr[ac].first = val[i]*r, arr[ac].second = 1, ac++;
    }
    sort(arr, arr+ac);
    ll rs = 0, rr = ac - 1;
    while(n > 0 && rr >= 0){
        ps f = arr[rr--];
        rs += ll(f.first) * min(n, f.second);
        n -= f.second;
    }
    cout<<rs<<endl;
    return 0;
}
