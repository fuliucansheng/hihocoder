#include <iostream>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 100010;
ll arr[maxn], n;
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n;
    ll s = 0;
    for(int i=0;i<n;i++) cin>>arr[i], s += arr[i];
    set<ll> p1, p2;
    map<ll,ll> dict;
    for(int i=0;i<3;i++){
        if((s+i)%3 == 0) p1.insert((s+i)/3);
        if((s-i)%3 == 0) p1.insert((s-i)/3);
    }
    for(auto p:p1) p2.insert(2*p+1), p2.insert(2*p), p2.insert(2*p-1);
    ll ns = arr[0], rs = 0;
    for(int i=1;i<n;i++){
        if(p2.find(ns) != p2.end()){
            for(ll x=-1;x<2;x++)
                if((ns+x)%2 == 0){
                    ll p = (ns+x)/2, c = ns-p, r = s-ns;
                    if(max(p,max(c,r)) - min(p,min(c,r)) < 2) rs += dict[p];
                }
        }
        if(p1.find(ns) != p1.end()) dict[ns]++;
        ns += arr[i];
    }
    cout<<rs<<endl;
    return 0;
}

