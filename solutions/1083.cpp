#include <iostream>
#include <iomanip>
using namespace std;
typedef pair<double,double> ps;
const int maxn = 8010;
ps arr[maxn];
int n;
double cross(ps a, ps b){
    ps aa = ps(a.first - arr[0].first, a.second - arr[0].second), bb = ps(b.first - arr[0].first, b.second - arr[0].second);
    return aa.first * bb.second - aa.second * bb.first;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
        double area = 0, xg = 0, yg = 0, rs = 0, S = 0;
        for(int i=1;i<n-1;i++) {
            area = cross(arr[i], arr[i+1]);
            xg = arr[0].first + arr[i].first + arr[i+1].first;
            yg = arr[0].second + arr[i].second + arr[i+1].second;
            area /= 2, xg /= 3, yg /= 3;
            rs += (xg + yg) * area;
            S += area;
        }
        if(S < 0) rs *= -1;
        cout<<fixed<<setprecision(2)<<rs<<endl;
    }
    return 0;
}
