#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1050;
struct node{
    double x,y,r;
};
node arr[maxn];
vector<int> graph[maxn];
int fa[maxn],deg[maxn];
bool is_cover(node a, node b){
    return pow(a.r-b.r,2) >= pow(a.x-b.x,2) + pow(a.y-b.y,2);
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(fa, 0, sizeof(fa));memset(deg, 0, sizeof(deg));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].x>>arr[i].y>>arr[i].r;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)
            if(is_cover(arr[i], arr[j])){
                if(arr[i].r >= arr[j].r) graph[i].push_back(j), deg[j]++;
                else graph[j].push_back(i), deg[i]++;
            }
    }
    queue<int> Q;
    for(int i=1;i<=n;i++) if(deg[i] == 0) Q.push(i);
    while(!Q.empty()){
        int f = Q.front();Q.pop();
        for(auto v:graph[f]) {
            deg[v]--;
            if(deg[v] == 0) Q.push(v), fa[v] = f;
        }
    }
    for(int i=1;i<=n;i++) cout<<fa[i]<<endl;
    return 0;
}
