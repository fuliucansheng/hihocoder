#include <bits/stdc++.h>
using namespace std;
#define eps 0.000001
#define d(a, b) ((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second))
typedef pair<double,double> pdd;
const int maxn = 2010;
struct node{
    double first, second;
    int w;
}arr[maxn];
pdd get_center(node a, node b){
    pdd ab = pdd((a.first + b.first) / 2, (a.second + b.second) / 2);
    double d = sqrt(1.0 - d(a, ab));
    if(a.first == b.first) return pdd(ab.first, ab.second - d);
    double angle = atan((b.first - a.first) / (a.second - b.second));
    return pdd(ab.first - d * cos(angle), ab.second - d * sin(angle));
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, ans = 0; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second>>arr[i].w;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(d(arr[i], arr[j]) <= 4.0 + eps){
                pdd ctr = get_center(arr[i], arr[j]);
                int cnt = 0;
                for(int k=0;k<n;k++) if(d(arr[k], ctr) <= 1 + eps) cnt += arr[k].w;
                ans = max(ans, cnt);
            }
    for(int i=0;i<n;i++) ans = max(ans, arr[i].w);
    cout<<ans<<endl;
    return 0;
}
