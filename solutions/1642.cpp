#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const int maxn = 1e5+50;
typedef pair<double,double> p;
p arr[maxn];
int main(){
    //freopen("../input.txt", "r", stdin);
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x>>y;
        arr[i].first = x - y, arr[i].second = x + y;
    }
    sort(arr, arr+n);
    double res = 0, mm = arr[0].first;
    for(int i=0;i<n;i++) {
        if(arr[i].second > mm){
            double l = arr[i].second - arr[i].first, pl = 0;
            if(mm > arr[i].first) pl = mm - arr[i].first;
            res += 0.25*l*l - 0.25*pl*pl;
            mm = arr[i].second;
        }
    }
    cout<<fixed<<setprecision(2)<<res<<endl;
    return 0;
}
