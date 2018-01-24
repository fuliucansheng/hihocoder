#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 100010, maxm = 10010;
struct node{
    int v, p, t;
    bool operator <(node x){
        return v > x.v;
    }
} arr[maxn];
vector<int> rec[maxm], jar;
int c[maxm], m, n, k;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        memset(c, 0, sizeof(c));
        jar.clear();
        for(int i=0;i<maxm;i++) rec[i].clear();
        cin>>n>>m>>k;
        for(int i=0;i<n;i++) cin>>arr[i].v>>arr[i].p>>arr[i].t;
        sort(arr, arr+n);
        for(int i=1;i<=m;i++) cin>>c[i];
        ll rs = 0;
        for(int i=0;i<n;i++){
            if(arr[i].t) continue;
            int p = arr[i].p;
            if(rec[p].size() < c[p]) rec[p].push_back(arr[i].v), rs += arr[i].v;
        }
        for(int i=0;i<n;i++){
            if(!arr[i].t) continue;
            int p = arr[i].p;
            if((int)rec[p].size() < c[p]) jar.push_back(arr[i].v);
            else if(c[p] > 0) jar.push_back(arr[i].v-rec[p][c[p]-1]);
            c[p]--;
        }
        sort(jar.begin(), jar.end(), greater<int>());
        for(int i=0;i<k&&i<jar.size();i++){
            if(jar[i] <= 0) break;
            rs += jar[i];
        }
        cout<<rs<<endl;
    }
    return 0;
}
