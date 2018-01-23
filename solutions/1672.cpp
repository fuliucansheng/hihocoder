#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 100010;
ps arr[maxn];
int n;
set<int> rec;
void step(){
    int px = 0, pv = arr[0].second;
    for(int i=0;i<n;i++){
        if(arr[i].first > pv){
            rec.insert(pv);
            for(int j=px;j<i;j++) {
                if(arr[j].first == pv) arr[j].first++;
                if(arr[j].second == pv) arr[j].second--;
            }
            px = i, pv = arr[i].second;
        }
        pv = min(pv, arr[i].second);
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr, arr+n);
    step(); step();
    cout<<rec.size()+2<<endl;
    return 0;
}
