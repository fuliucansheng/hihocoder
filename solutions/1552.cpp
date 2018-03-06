#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
const int maxn = 100010;
struct node{
    pii a, b;
} arr[maxn], bg;
pii get_region(vector<ppi> rr, int sx, int ex, int d){
    pii ret;
    int c = 0, px = sx, s = 0;
    for(auto p:rr){
        if(p.first.first != px){
            if(!s && c != d) ret.first = px, s = 1;
            else if(s && c == d) { ret.second = px; break; }
        }
        if(p.second == -1) c -= p.first.second;
        else c += p.first.second;
        px = p.first.first;
    }
    if(!s) ret.first = px, ret.second = ex;
    if(s && c != d) ret.second = px;
    return ret;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n; n--;
    cin>>bg.a.first>>bg.a.second>>bg.b.first>>bg.b.second;
    for(int i=0;i<n;i++){
        pii &aa = arr[i].a, &bb = arr[i].b;
        cin>>aa.first>>aa.second>>bb.first>>bb.second;
    }
    vector<ppi> xx, yy;
    for(int i=0;i<n;i++){
        xx.push_back(ppi(pii(arr[i].a.first, arr[i].b.second - arr[i].a.second), 1));
        xx.push_back(ppi(pii(arr[i].b.first, arr[i].b.second - arr[i].a.second), -1));
        yy.push_back(ppi(pii(arr[i].a.second, arr[i].b.first - arr[i].a.first), 1));
        yy.push_back(ppi(pii(arr[i].b.second, arr[i].b.first - arr[i].a.first), -1));
    }
    sort(xx.begin(), xx.end()); sort(yy.begin(), yy.end());
    pii x = get_region(xx, bg.a.first, bg.b.first, bg.b.second - bg.a.second), y = get_region(yy, bg.a.second, bg.b.second, bg.b.first - bg.a.first);
    cout<<x.first<<" "<<y.first<<" "<<x.second<<" "<<y.second<<endl;
    return 0;
}
