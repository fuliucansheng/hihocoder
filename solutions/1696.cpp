#include <bits/stdc++.h>
using namespace std;
#define d(a, b) sqrt(double(a.first - b.first) * double(a.first - b.first) + double(a.second - b.second) * double(a.second - b.second))
typedef pair<int,int> pii;
const int maxn = 105;
pii pnt[maxn];
double dis[maxn];
int n;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>pnt[i].first>>pnt[i].second;
    double sum = 0;
    for(int i=0;i+1<n;i++) dis[i] = d(pnt[i], pnt[i+1]), sum += dis[i];
    double mid = sum / 2;
    for(int i=0;i+1;i++) if(mid > dis[i]) mid -= dis[i]; else{
            int dx = pnt[i+1].first - pnt[i].first, dy = pnt[i+1].second - pnt[i].second;
            double rx = (mid / dis[i]) * dx + pnt[i].first, ry = (mid / dis[i]) * dy + pnt[i].second;
            return cout<<fixed<<setprecision(1)<<rx<<" "<<ry<<endl, 0;
        }
    return 0;
}
