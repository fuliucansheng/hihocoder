#include <bits/stdc++.h>
using namespace std;
#define EARTH_RADIUS 6000
#define PI 3.14159265358979323846
typedef pair<double, double> pdd;
double rad(double d){
    return d * PI / 180.0;
}
double dis(double lat1, double lon1, double lat2, double lon2){
    double radlat1 = rad(lat1), radlat2 = rad(lat2);
    double a = radlat1 - radlat2, b = rad(lon1) - rad(lon2);
    double s = 2 * asin(sqrt(pow(sin(a/2), 2) + cos(radlat1) * cos(radlat2) * pow(sin(b/2), 2)));
    s *= EARTH_RADIUS;
    s = llroundl(s*10000) / 10000.0;
    return s;
}
int main() {
    //freopen("../input.txt", "r", stdin);
    int n, m; cin>>n>>m;
    pdd pnt[n];
    for(int i=0;i<n;i++) cin>>pnt[i].first>>pnt[i].second;
    for(int i=0;i<m;i++){
        double x, y; cin>>x>>y;
        int ans = 0;
        for(int j=0;j<n;j++) if(dis(x, y, pnt[j].first, pnt[j].second) < 0.5) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
