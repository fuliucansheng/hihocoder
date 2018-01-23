#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define d(p1,p2) (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)))
const double eps = 1e-6;
struct node{
    double x, y;
};
double a(node p1, node p2, node p3){
    double d1 = d(p1, p2), d2 = d(p2, p3), d3 = d(p3, p1);
    double s = (d1 + d2 + d3)/2;
    return sqrt(s*(s-d1)*(s-d2)*(s-d3));
}
int main(){
    freopen("../input.txt", "r", stdin);
    int t, n, u; cin>>t;
    while(t--){
        cin>>n>>u;
        node arr[n];
        for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
        double mx = -1, mn = -1;
        node hip, hop;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++) {
                    double ae = a(arr[i],arr[j],arr[k]);
                    if(fabs(ae) <= eps) continue;
                    double x = (arr[i].x+arr[j].x+arr[k].x)/3, y = (arr[i].y+arr[j].y+arr[k].y)/3;
                    if(mx == -1 || ae - mx > eps || (fabs(ae - mx) <= eps && (x - hip.x > eps || (fabs(x - hip.x) <= eps && y - hip.y > eps)))) mx = ae, hip.x = x, hip.y = y;
                    if(mn == -1 || mn - ae > eps || (fabs(ae - mn) <= eps && (hop.x - x > eps || (fabs(x - hop.x) <= eps && hop.y - y > eps)))) mn = ae, hop.x = x, hop.y = y;
                }
        cout<<fixed<<setprecision(2)<<d(hip,hop)/(2.0*u)<<endl;
    }
    return 0;
}

